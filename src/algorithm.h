# ifndef ALGORITHM_H
# define ALGORITHM_H

# include "main.h"

// vector<int> getwire_surr(vector<vector<ll>> &adj, vector<vector<ll>> &revadj, ll numnodes, ll wire, vector<int> &ntype);

// vector<int> getbranch_sur(vector<vector<ll>> &adj, ll numnodes, ll wire, ll node);

void PODEM(vector<vector<pair<ll, ll>>> &adj, vector<vector<pair<ll, ll>>> &revadj, ll numnodes, vector<int> ntype, vector<int> &fpi, ll wire, char state);

vector<vector<ll>> Objective(vector<vector<pair<ll, ll>>> &adj, vector<vector<pair<ll, ll>>> &revadj, ll numnodes, ll npi, vector<int> ntype, ll u, ll v, ll wire, char state);
# endif