# include "algorithm.h"

// vector<int> getwire_surr(vector<vector<ll>> &adj, vector<vector<ll>> &revadj, ll numnodes, ll wire, vector<int> &ntype)
// {
//     vector<int> surr (6);
//     ll v, w;
//     for(ll i = 0; i < numnodes; i++)
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

// vector<int> getbranch_sur(vector<vector<ll>> &adj, ll numnodes, ll wire, ll node)
// {
//     vecor<int> bsurr;
//     ll v, w;;
//     for(auto it : adj[node - 1])
//     {
//         v = it.first;
//         w = it.second;
//         bsurr.push_back(w); 
//     }
//     return bsurr;
// }

void PODEM(vector<vector<pair<ll, ll>>> &adj, vector<vector<pair<ll, ll>>> &revadj, ll numnodes, vector<int> ntype, vector<int> &fpi, ll wire, char state)
{
    ll u = 0, v, w, npi = fpi.size();
    for(int i = 0; i < numnodes; i++)
    {
        for(auto it : adj[i])
        {
            v = it.first;
            w = it.second;
            if(w == wire + 1)
            {
                u = i + 1;
                break;
            }
        }
    }
    if(u == 0)
    {
        cout << "Please give a valid wire\n";
        return;
    }
    // objective is to Initialise the fault by assigning primary inputs
    vector<vector<ll>> choices;
    choices = Objective(adj, revadj, numnodes, npi, ntype, u, v, w, state);
}

vector<vector<ll>> Objective(vector<vector<pair<ll, ll>>> &adj, vector<vector<pair<ll, ll>>> &revadj, ll numnodes, ll npi, vector<int> ntype, ll u, ll v, ll wire, char state)
{
    vector<vector<ll>> ans;
    vector<ll> pi (npi, -1);
}

