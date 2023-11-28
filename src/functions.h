# ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "main.h"

void addEdge(vector<vector<pair<ll, ll>>> &adj, ll u, ll v, ll wire);

void printcircuit(vector<vector<pair<ll, ll>>> &adj, ll numnodes);

# endif