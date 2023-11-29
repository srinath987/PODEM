# ifndef MAINHEADER_H
# define MAINHEADER_H

# include <bits/stdc++.h>

using namespace std;

#define vvp vector<vector<pair<int, int>>>
#define vp vector<pair<int, int>>
#define vi vector<int>
#define pi pair<int, int>
#define mii map<int,int>

vvp adj;
vvp revadj;
mii state; 
mii ntype;
vi inputs;
vi outputs;
int numnodes, numedges;

# endif