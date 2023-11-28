# ifndef __FUNCTIONS_H
# define __FUNCTIONS_H

# include "main.h"

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wire);

void printcircuit(vector<vector<pair<int, int>>> &adj, int numnodes);

# endif