# include "main.h"

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll numnodes, npi;
    cout << "Enter the number of nodes (Branching points, gates, inputs, outputs): \n";
    cin >> numnodes;
    ll numedges;
    cout << "Enter the number of edges (Wires): \n";
    cin >> numedges;
    vector<vector<pair<ll, ll>>> adj(numnodes, vector<pair<ll, ll>> (0));
    vector<vector<pair<ll, ll>>> revadj(numnodes, vector<pair<ll, ll>> (0));
    vector<int> ntype(numnodes);
    cout << "Enter connections in netlist format (node1 node2 wireid): \n";
    for(ll i = 0; i < numedges; i++)
    {
        ll u, v, wire;
        cin >> u >> v >> wire;
        addEdge(adj, u, v, wire);
        addEdge(revadj, v, u, wire);
    }
    cout << "Enter the type of node: \n -2: output\n -1: input\n 0: branching point\n 1: AND\n 2: OR\n 3: NAND\n 4: NOR\n 5: XOR\n 6: XNOR\n 7: NOT\n";
    for(ll i = 0; i < numnodes; i++)
    {
        int type;
        cin >> type;
        ntype[i] = type;
        if(type == -1)
        {
            npi++;
        }
    }
    printcircuit(adj, numnodes);
    for (ll i = 0; i < numnodes; i++)
    {
        cout << "Node " << i + 1 << " is of type " << ntype[i] << endl;
    }
    int fwire;
    char f_state;
    char f_states[2] = {'D', 'E'};
    vector<int> fpi(npi);
    // int wire_sur[numedges][6];
    // vector<vector<int>> branchsurr;
    // vector<int> tempwsurr;
    // for(ll k = 0; k < numedges; k++)
    // {
    //     for(int l = 0; l < 6; l++)
    //     {
    //         wire_sur[k][l] = 0;
    //     }
    // }
    // for(ll k = 0; k < numedges; k++)
    // {
    //     tempsurr = getwire_sur(adj, numnodes, k, ntype);
    //     for(int l = 0; l < 6; l++)
    //         wire_sur[k][l] = tempsurr[l];
    // }
    // for(ll k = 0; k < numedges; k++)
    // {
    //     if(ntype[wire_surr[k][1] - 1] == 0)
    //     {
    //         branchsurr.push_back(getbranch_surr(adj, numnodes, k, wire_surr[k][1]));
    //     }
    // }
    for(int i = 0; i < 2; i++)
    {
        for(ll j = 0; j < numedges; j++)
        {
            cout << "Considering s-a-" << i << " for wire " << j << endl;

            fwire = j;
            f_state = f_states[i];
            
            PODEM(adj, revadj, numnodes, ntype, fpi, fwire, f_state);
        }
    }
    
    return 0;
}