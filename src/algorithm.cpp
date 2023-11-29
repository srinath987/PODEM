#include "mainheader.cpp"
#include "algorithm.h"

// void forwardimpl(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, vector<int> &ntype, vector<int> &state, int node, int wire, char val)
// {
// }

// bool PODEM(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, int numnodes, vector<int> ntype, vector<int> &fpi, int wire, char fault)
// {
//     // if D or D' at output return true
//     for(int i = 0; i < outputs.size(); i++) {
//         if(state[outputs[i]] == 2 || state[outputs[i]] == 3) {
//             return true;
//         }
//     }

//     vector<int> nv = Objective(adj, revadj, numnodes, npi, ntype, wire, fault);
//     int n = nv[0];
//     int v = nv[1];

//     vector<int> pv = backtrace(revadj, ntype, state, n, v);
//     int p = pv[0];
//     int w = pv[1];

//     forwardimpl(adj, revadj, ntype, p, w);

//     if(PODEM(adj, revadj, numnodes, ntype, fpi, wire, fault))
//     {
//         return true;
//     }

//     if(w == 0)
//     w = 1;
//     else
//     w = 0;

//     forwardimpl(adj, revadj, ntype, p, w);

//     if(PODEM(adj, revadj, numnodes, ntype, fpi, wire, fault))
//     {
//         return true;
//     }

//     forwardimpl(adj, revadj, ntype, p, -1);

//     return false;
// }

vector<int> Objective(int wire, int fault)
{
    // returns the objective (n, v) n -> node v -> value
    if (state[wire] == -1)
    {
        int currnode;
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (adj[i][j].second == wire)
                {
                    currnode = i;
                }
            }
            if (fault == 0)
            {
                return {currnode, wire, 1};
            }
            else
            {
                return {currnode, wire, 0};
            }
        }
    }
    // propagate the fault to the output
    for (auto it : state)
    {
        if (it.second == 2 || it.second == 3)
        {
            int currnode, nxtnode;
            for (int i = 0; i < adj.size(); i++)
            {
                for (int j = 0; j < adj[i].size(); j++)
                {
                    if (adj[i][j].second == it.first)
                    {
                        currnode = i;
                        nxtnode = adj[i][j].first;
                        for (int k = 0; k < adj[nxtnode].size(); k++)
                        {
                            if (state[adj[nxtnode][k].second] == -1)
                            {
                                for (int l = 0; l < revadj[nxtnode].size(); l++)
                                {
                                    if (revadj[nxtnode][l].first != currnode && state[revadj[nxtnode][l].second] == -1)
                                    {
                                        if (ntype[nxtnode] == 6 || ntype[nxtnode] == 2 || ntype[nxtnode] == 4 || ntype[nxtnode] == 5)
                                            return {revadj[nxtnode][l].first, revadj[nxtnode][l].second, 0};
                                        else
                                            return {revadj[nxtnode][l].first, revadj[nxtnode][l].second, 1};
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return {-1, -1, -1};
}

pair<pi, int> backtrace(int u, int &obj)
{
    vi visited(numnodes, 0);
    pair<pi, int> assign = {{0, 0}, -1};
    bool backtraced = false;
    visited[u - 1] = 1;
    if (ntype[u] == 3 || ntype[u] == 4 || ntype[u] == 6 || ntype[u] == 7)
    {
        obj = 1 - obj;
    }
    dfs(visited, u, obj, assign, backtraced);
    return assign;
}

void dfs(vi &visited, int node, int &obj, pair<pi, int> &assign, bool &backtraced)
{
    visited[node - 1] = 1;
    cout << "\n"
         << node << "\n";
    int v, w;
    for (auto it : revadj[node - 1])
    {
        v = it.first;
        w = it.second;
        if (visited[v - 1] != 1)
        {
            if (ntype[v] == 3 || ntype[v] == 4 || ntype[v] == 6 || ntype[v] == 7)
            {
                obj = 1 - obj;
                dfs(visited, v, obj, assign, backtraced);
                if (backtraced == true)
                {
                    return;
                }
                obj = 1 - obj;
            }
            if (ntype[v] == -1)
            {
                if (state[w] == -1)
                {
                    assign.first.first = v;
                    assign.first.second = w;
                    assign.second = obj;
                    backtraced = true;
                    return;
                }
            }
        }
    }
}