# include "algorithm.h"

void forwardimpl(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, vector<int> &ntype, vector<int> &state, int node, int wire, char val)
{
}

bool PODEM(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, int numnodes, vector<int> ntype, vector<int> &fpi, int wire, char fault)
{
    // if D or D' at output return true
    for(int i = 0; i < outputs.size(); i++) {
        if(state[outputs[i]] == 2 || state[outputs[i]] == 3) {
            return true;
        }
    }

    vector<int> nv = Objective(adj, revadj, numnodes, npi, ntype, wire, fault);
    int n = nv[0];
    int v = nv[1]; 
    
    vector<int> pv = backtrace(revadj, ntype, state, n, v);
    int p = pv[0];
    int w = pv[1];

    forwardimpl(adj, revadj, ntype, p, w);

    if(PODEM(adj, revadj, numnodes, ntype, fpi, wire, fault))
    {
        return true;
    }

    if(w == 0)
    w = 1;
    else
    w = 0;

    forwardimpl(adj, revadj, ntype, p, w);

    if(PODEM(adj, revadj, numnodes, ntype, fpi, wire, fault))
    {
        return true;
    }

    forwardimpl(adj, revadj, ntype, p, -1);

    return false;
}

vector<int> Objective(int wire, int fault)
{
    // returns the objective (n, v) n -> node v -> value
    if(state[wire] == -1) {
        if(fault == 0) {
            return {wire, 1};
        }
        else {
            return {wire, 0};
        }
    }

    // propagate the fault to the output
    for(auto it : state) {
        if(it.second == 2 || it.second == 3) {
            int node = -1;
            for(int i = 0; i < adj.size(); i++) {
                for(int j = 0; j < adj[i].size(); j++) {
                    if(adj[i][j].second == it.first) {
                        node = adj[i][j].first;
                        for(int k = 0; k < adj[node].size(); k++) {
                            if(state[adj[node][k].second] == -1) {
                                
                            }
                        }
                    }
                }
            }
        }
    }

    return {-1, -1};
}

pair<pi, int> backtrace(vvp &revadj, vi &ntype, vi &state, int u, int &obj)
{
    int n = ntype.size();
    vi visited (n);
    pair<pi, int> assign = {{0, 0}, -1};
    visited[u - 1] = 1;
    if(ntype[u - 1] == 3 || ntype[u - 1] == 4 || ntype[u - 1] == 6 || ntype[u - 1] == 7)
    {
        obj = 1 - obj;
    }
    dfs(revadj, visited, ntype, state, u, obj, assign);
    return assign;
}

void dfs(vvp &revadj, vi &visited, vi &ntype, vi &state, int node, int &obj, pair<pi, int> &assign)
{
    visited[node - 1] = 1;
    int v, w;
    for(auto it : revadj[node - 1])
    {
        v = it.first;
        w = it.second;
        if(visited[v - 1] != 1)
        {
            if(ntype[v - 1] == 3 || ntype[v - 1] == 4 || ntype[v - 1] == 6 || ntype[v - 1] == 7)
            {
                obj = 1 - obj;
            }
            if(ntype[v - 1] == -1)
            {
                if(state[v - 1] == -1)
                {
                    assign.first.first = v;
                    assign.first.second = w;
                    assign.second  = obj;
                    return;
                }
            }
            dfs(revadj, visited, ntype, state, v, obj, assign);
        }
    }
}

