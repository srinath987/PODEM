# include "algorithm.h"

// vector<int> getwire_surr(vector<vector<int>> &adj, vector<vector<int>> &revadj, int numnodes, int wire, vector<int> &ntype)
// {
//     vector<int> surr (6);
//     int v, w;
//     for(int i = 0; i < numnodes; i++)
//     {
//         for(auto it2: adj[i])
//         {
//             v = it2.first;
//             w = it2.second;
//             if(wire == w - 1)
//             {
//                 surr[0] = i + 1;
//                 surr[1] = v;
//                 break;
//             }
//         }
//     }
//     int in = 2;
//     for(auto it : revadj[surr[0] - 1])
//     {
//         v = it.first;
//         w = it.second;
//         if(ntype[surr[0] - 1] == 0)
//         {
//             surr[2] = w;
//             surr[3] = w;
//         }
//         else
//         {
//             surr[in] = w;
//             in++;
//         }
//     }
//     if(ntype[surr[1] - 1] != -1)
//     {
//         surr[4] = adj[surr[1] - 1][0].second;
//     }
//     for(auto it : revadj[surr[1] - 1])
//     {
//         v = it.first;
//         w = it.second;
//         if(w != wire)
//         {
//             surr[5] = w;
//         }
//     }
//     return surr;
// }

// vector<int> getbranch_sur(vector<vector<int>> &adj, int numnodes, int wire, int node)
// {
//     vecor<int> bsurr;
//     int v, w;;
//     for(auto it : adj[node - 1])
//     {
//         v = it.first;
//         w = it.second;
//         bsurr.push_back(w); 
//     }
//     return bsurr;
// }

// bool PODEM(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, int numnodes, vector<int> ntype, vector<int> &fpi, int wire, char fault)
// {
//     // if D or D' at output return true
    

//     // if test impossible return false
// }

// vector<int> Objective(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, int numnodes, int npi, vector<int> ntype, int u, int v, int wire, char state)
// {
//     // returns the objective (n, v) n -> node v -> value
//     if(n == 'x')
//     {
//         return ;
//     }

// }

pair<pi, int> backtrace(int u, int &obj)
{
    int n = ntype.size();
    vi visited (n);
    pair<pi, int> ass = {{0, 0}, -1};
    bool backtraced = false;
    visited[u - 1] = 1;
    if(ntype[u - 1] == 3 || ntype[u - 1] == 4 || ntype[u - 1] == 6 || ntype[u - 1] == 7)
    {
        obj = 1 - obj;
    }
    dfs(revadj, visited, ntype, state, u, obj, ass, backtraced);
    return ass;
}

void dfs(vvp &revadj, vi &visited, vi &ntype, vi &state, int node, int &obj, pair<pi, int> &ass, bool &backtraced)
{
    visited[node - 1] = 1;
    cout << "\n" << node << "\n";
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
                dfs(revadj, visited, ntype, state, v, obj, ass, backtraced);
                if(backtraced == true)
                {
                    return;
                }
                obj = 1 - obj;
            }
            if(ntype[v - 1] == -1)
            {
                if(state[v - 1] == -1)
                {
                    ass.first.first = v;
                    ass.first.second = w;
                    ass.second  = obj;
                    backtraced = true;
                    return;
                }
            }
        }
    }
}

