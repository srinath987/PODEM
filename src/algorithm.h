# ifndef ALGORITHM_H
# define ALGORITHM_H

# include "main.h"

// vector<int> getwire_surr(vector<vector<int>> &adj, vector<vector<int>> &revadj, int numnodes, int wire, vector<int> &ntype);

// vector<int> getbranch_sur(vector<vector<int>> &adj, int numnodes, int wire, int node);

void PODEM(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, int numnodes, vector<int> ntype, vector<int> &fpi, int wire, char state);

vector<vector<int>> Objective(vector<vector<pair<int, int>>> &adj, vector<vector<pair<int, int>>> &revadj, int numnodes, int npi, vector<int> ntype, int u, int v, int wire, char state);

pair<pi, int> backtrace(int u, int &obj);

void dfs(vvp &revadj, vi &visited, vi &ntype, vi &state, int node, int &obj, pair<pi, int> &ass, bool &backtraced);

# endif