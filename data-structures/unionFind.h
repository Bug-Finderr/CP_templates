#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

// Macros
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define int long long      // Comment this line if you want to use actual int
#define double long double // Comment this line if you want to use actual double

// Aliases
using ull = unsigned long long;
using p = pair<int, int>;
using v = vector<int>;
using m = map<int, int>;
using vv = vector<v>;
using us = unordered_set<int>;

class DSU
{
public:
    v parent, rank;

    DSU(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        return parent[x] = parent[x] == x ? x : find(parent[x]);
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y])
            ++rank[x];
    }
};