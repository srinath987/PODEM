# include "functions.h"

void addEdge(vector<vector<pair<ll, ll>>> &adj, ll u, ll v, ll wire)
{
    adj[u - 1].push_back(make_pair(v, wire));
}

void printcircuit(vector<vector<pair<ll, ll>>> &adj, ll numnodes)
{
    for(ll i = 0; i < numnodes; i++)
    {
        cout << i + 1 << ": ";
        for(auto it : adj[i])
        {
            cout << it.first << " " << it.second << " ;";
        }
        cout << "\n";
    }
}
