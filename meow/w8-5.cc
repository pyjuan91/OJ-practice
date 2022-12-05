#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
class DisjointSet {
private:
    vector<int> parent;
    int find_root(int x)
    {
        if (parent[x] == x)
            return x;
        int root = find_root(parent[x]);
        return parent[x] = root;
    }

public:
    DisjointSet(size_t n)
        : parent(n + 1)
    {
        init();
    }
    void init()
    {
        for (size_t i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }
    bool Same(int a, int b)
    {
        return find_root(a) == find_root(b);
    }
    void Union(int a, int b)
    {
        parent[find_root(a)] = find_root(b);
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, l, r;
    cin >> n >> q;
    DisjointSet djs(n);
    while (q--) {
        cin >> l >> r;
        djs.Union(l - 1, r);
    }
    if (djs.Same(0, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}