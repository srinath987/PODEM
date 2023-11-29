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

void fimply(int pinp, int val)
{
    for(auto it : adj[pinp - 1])
    {
        state[it.second] = val;
    }
    int v, w;
    int logic, unknown, df, ef;
    for(auto it1 : adj[pinp - 1])
    {
        v = it1.first;
        w = it1.second;
        logic = -1;
        unknown = 0;
        df = 0;
        ef = 0;
        if(ntype[v] == 0)
        {
            fimply(v, val);
            continue;  
        }
        else if(ntype[v] == 7)
        {
            if(val == 0 || val == 1)
            {
                fimply(v, 1 - val);
            }
            else if(val == 2)
            {
                fimply(v, 3);
            }
            else if(val == 3)
            {
                fimply(v, 2);
            }
            continue;
        }
        for(auto it2 : revadj[v - 1])
        {
            if(state[it2.second] == -1)
            {
                unknown = 1;
            }
            else if(state[it2.second] == 2)
            {
                df = 1;
            }
            else if(state[it2.second] == 3)
            {
                ef = 1;
            }
            else
            {
                if(logic == -1)
                {
                    logic = state[it2.second];
                }
                else
                {
                    if(ntype[v] == 1 || ntype[v] == 3)
                    {
                        logic = logic & state[it2.second];
                    }
                    else if(ntype[v] == 2 || ntype[v] == 4)
                    {
                        logic = logic | state[it2.second];
                    }
                    else if(ntype[v] == 5 || ntype[v] == 6)
                    {
                        logic = logic ^ state[it2.second];
                    }
                }
            }
        }
        if(ntype[v] == 1 || ntype[v] == 3)
        {
            if(logic == 0)
            {
                if(ntype[v] == 3)
                {
                    fimply(v, 1);
                }
                else
                {
                    fimply(v, 0);
                }
            }
            else if(df == 1 && ef == 1)
            {
                if(ntype[v] == 3)
                {
                    fimply(v, 1);
                }
                else
                {
                    fimply(v, 0);
                }
            }
            else if(df == 1 && ef == 0)
            {
                if(ntype[v] == 3)
                {
                    fimply(v, 3);
                }
                else
                {
                    fimply(v, 2);
                }
            }
            else if(df == 0 && ef == 1)
            {
                if(ntype[v] == 3)
                {
                    fimply(v, 2);
                }
                else
                {
                    fimply(v, 3);
                }
            }
        }
        else if(ntype[v] == 2 || ntype[v] == 4)
        {
            if(logic == 1)
            {
                if(ntype[v] == 4)
                {
                    fimply(v, 0);
                }
                else
                {
                    fimply(v, 1);
                }
            }
            else if(df == 1 && ef == 1)
            {
                if(ntype[v] == 4)
                {
                    fimply(v, 0);
                }
                else
                {
                    fimply(v, 1);
                }
            }
            else if(df == 1 && ef == 0)
            {
                if(ntype[v] == 4)
                {
                    fimply(v, 3);
                }
                else
                {
                    fimply(v, 2);
                }
            }
            else if(df == 0 && ef == 1)
            {
                if(ntype[v] == 4)
                {
                    fimply(v, 2);
                }
                else
                {
                    fimply(v, 3);
                }
            }
        }
        else if(ntype[v] == 5 || ntype[v] == 6)
        {
            if(logic == 1)
            {
                if(ntype[v] == 6)
                {
                    fimply(v, 0);
                }
                else
                {
                    fimply(v, 1);
                }
            }
            else if(df == 1 && ef == 1)
            {
                if(ntype[v] == 6)
                {
                    fimply(v, 0);
                }
                else
                {
                    fimply(v, 1);
                }
            }
            else if(df == 1 && ef == 0)
            {
                if(ntype[v] == 6)
                {
                    fimply(v, 3);
                }
                else
                {
                    fimply(v, 2);
                }
            }
            else if(df == 0 && ef == 1)
            {
                if(ntype[v] == 6)
                {
                    fimply(v, 2);
                }
                else
                {
                    fimply(v, 3);
                }
            }
        }
    }
}