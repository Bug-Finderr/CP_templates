#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/segment-tree-data-structure/

// Macros
#define int long long

// Aliases
using v = vector<int>;

class segmentTree
{
private:
    int n, identity;
    v tree;

public:
    int merge(int a, int b)
    {
        return a + b;
    }

    segmentTree(int n, int identity) : n(n), identity(identity)
    {
        tree.resize(4 * n, identity);
    }

    // Update a[queryIdx] = val
    void update(int qIdx, int val)
    {
        function<void(int, int, int)> f = [&](int tIdx, int l, int r) -> void
        {
            if (l == r)
            {
                tree[tIdx] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (qIdx <= mid)
                f(2 * tIdx, l, mid);
            else
                f(2 * tIdx + 1, mid + 1, r);

            // Heap/Priority Queue idea
            // leftChild = 2 * tIdx + 1, l, mid
            // rightChild = 2 * tIdx + 2, mid + 1, r
            tree[tIdx] = merge(tree[2 * tIdx], tree[2 * tIdx + 1]);
        };
        f(1, 0, n - 1);
    }

    int query(int l, int r)
    {
        function<int(int, int, int)> f = [&](int tIdx, int tl, int tr) -> int
        {
            if (l > tr || r < tl) // No overlap
                return identity;

            if (l <= tl && tr <= r) // Complete overlap
                return tree[tIdx];

            int mid = (tl + tr) / 2;
            return merge(f(2 * tIdx, tl, mid), f(2 * tIdx + 1, mid + 1, tr)); // Partial overlap
        };
        return f(1, 0, n - 1);
    }
};