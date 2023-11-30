#ifndef MAINHEADER_H
#define MAINHEADER_H

#include <bits/stdc++.h>

using namespace std;

#define vvp vector<vector<pair<int, int>>>
#define vp vector<pair<int, int>>
#define vi vector<int>
#define pi pair<int, int>
#define mii map<int, int>
#define msi map<string, int>
#define stm stack<map<int, int>>
#define mivp map<int, vp>

vvp adj, revadj;
mii state, ntype;
vi inputs, outputs;
int numnodes, numedges;

#endif