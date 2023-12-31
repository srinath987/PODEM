#include "mainheader.cpp"
#include "algorithm.cpp"
#include "functions.cpp"

int main()
{
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int npi;
    cout << "Enter the number of nodes (Branching points, gates, inputs, outputs): \n";
    cin >> numnodes;
    cout << "Enter the number of edges (Wires): \n";
    cin >> numedges;
    state.clear();
    for (int i = 0; i < numnodes; i++)
    {
        adj.push_back(vp(0));
        revadj.push_back(vp(0));
    }
    cout << "Enter connections in netlist format (node1 node2 wireid): \n";
    for (int i = 0; i < numedges; i++)
    {
        int u, v, wire;
        cin >> u >> v >> wire;
        addEdge(adj, u, v, wire);
        addEdge(revadj, v, u, wire);
        state[wire] = -1;
    }
    cout << "Enter the type of node: \n -2: output\n -1: input\n 0: branching point\n 1: AND\n 2: OR\n 3: NAND\n 4: NOR\n 5: XOR\n 6: XNOR\n 7: NOT\n";
    for (int i = 0; i < numnodes; i++)
    {
        int type;
        cin >> type;
        ntype[i + 1] = type;
        if (type == -1)
        {
            npi++;
            inputs.push_back(i + 1);
        }
        if (type == -2)
        {
            outputs.push_back(revadj[i][0].second);
        }
    }
    printcircuit(adj, numnodes);
    for (int i = 0; i < numnodes; i++)
    {
        cout << "Node " << i + 1 << " is of type " << ntype[i + 1] << endl;
    }

    int fwire, fval, nfaults;
    bool possible;
    // PODEM for given faults
    cout << "\n\n\n\nEnter the number of faults you wish to observe:\n";
    cin >> nfaults;
    vp faults;
    cout << "Enter the wire and fault to be detected: \n";
    for(int i = 0; i < nfaults; i++)
    {
        cin >> fwire >> fval;
        faults.push_back(make_pair(fwire, fval));
    }
    for(int i = 0; i < nfaults; i++)
    {
        cout << "\nFault " << faults[i].second << " on wire " << faults[i].first << ":\n";
        finit = false;

        possible = PODEM(faults[i].first, faults[i].second);
        if (possible)
        {
            cout << "It can be detected by test vector: \n";
            for (int k = 0; k < npi; k++)
            {
                cout << "Input: " << inputs[k] << " Value: ";
                if (state[adj[inputs[k] - 1][0].second] == 2)
                {
                    cout << "1"
                         << "\n";
                }
                else if (state[adj[inputs[k] - 1][0].second] == 3)
                {
                    cout << "0"
                         << "\n";
                }
                else if (state[adj[inputs[k] - 1][0].second] == -1)
                {
                    cout << "X"
                         << "\n";
                }
                else
                {
                    cout << state[adj[inputs[k] - 1][0].second] << "\n";
                }
            }
        }
        else
        {
            cout << "It cannot be detected by any test vector\n";
        }

        while (!stackstate.empty())
        {
            stackstate.pop();
        }
        for (auto it1 : state)
        {
            state[it1.first] = -1;
        }

    }
    


    // PODEM for all faults possible
    // for (auto it1 : state)
    // {
    //     cout << "Wire is " << it1.first << " " << it1.second << endl;
    // }
    // for (auto it : state)
    // {
    //     fwire = it.first;
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << "Fault " << j << " on wire " << fwire << ":\n";
    //         finit = false;
    //         possible = PODEM(fwire, j);
    //         if (possible)
    //         {
    //             cout << "It can be detected by test vector: \n";
    //             for (int k = 0; k < npi; k++)
    //             {
    //                 cout << "Input: " << inputs[k] << " Value: ";
    //                 if (state[adj[inputs[k] - 1][0].second] == 2)
    //                 {
    //                     cout << "1"
    //                          << "\n";
    //                 }
    //                 else if (state[adj[inputs[k] - 1][0].second] == 3)
    //                 {
    //                     cout << "0"
    //                          << "\n";
    //                 }
    //                 else if (state[adj[inputs[k] - 1][0].second] == -1)
    //                 {
    //                     cout << "X"
    //                          << "\n";
    //                 }
    //                 else
    //                 {
    //                     cout << state[adj[inputs[k] - 1][0].second] << "\n";
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             cout << "It cannot be detected by any test vector\n";
    //         }
    //         while (!stackstate.empty())
    //         {
    //             stackstate.pop();
    //         }
    //         for (auto it1 : state)
    //         {
    //             state[it1.first] = -1;
    //         }
    //         cout << "\n\n\n\n";
    //     }
    // }



    // // Debugging backtrace
    // int u = 10;
    // int obj = 0;
    // pair<pi, int> assign = backtrace(u, obj);
    // cout << "PI: " << assign.first.first << "PI wire: " << assign.first.second << "Value: " << assign.second;

    // // Debugging Objective
    // int u = 6;
    // int fault = 0;
    // state[6] = 2;
    // vi res = Objective(u, fault);
    // cout << "Objective: " << res[0] << " " << res[1] << " " << res[2] << endl;

    // // Debugging forward implication
    // state[16] = 3;
    // fimply(1, 0);
    // for(auto it : state)
    // {
    //     cout << "Wire is " << it.first << " " << it.second << endl;
    // }
    return 0;
}