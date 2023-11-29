# include "mainheader.cpp"
# include "functions.h"

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wire)
{
    adj[u - 1].push_back(make_pair(v, wire));
}

void printcircuit(vector<vector<pair<int, int>>> &adj, int numnodes)
{
    for(int i = 0; i < numnodes; i++)
    {
        cout << i + 1 << ": ";
        for(auto it : adj[i])
        {
            cout << it.first << " " << it.second << " ;";
        }
        cout << "\n";
    }
}
