#ifndef ALGORITHM_H
#define ALGORITHM_H

bool PODEM(int wire, int fault);

vector<int> Objective(int wire, int fault);

pair<pi, int> backtrace(int u, int &obj);

void dfs(vi &visited, int node, int &obj, pair<pi, int> &ass, bool &backtraced);

void fimply(int pinp, int val, int fwire, int fval);

#endif