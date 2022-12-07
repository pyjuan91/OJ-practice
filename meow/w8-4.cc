#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(size_t n)
        : parent(n + 1)
        , rank(n + 1)
    {
        for (size_t i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    bool IsInSameUnion(int a, int b)
    {
        return FindRoot(a) == FindRoot(b);
    }
    void Unite(int a, int b)
    {
        int pa = FindRoot(a), pb = FindRoot(b);
        if (rank[pa] > rank[pb])
            swap(pa, pb);
        parent[pa] = pb;
        if (rank[pa] == rank[pb])
            rank[pb] += 1;
    }
    int FindRoot(int x)
    {
        if (parent[x] == x)
            return x;
        int root = FindRoot(parent[x]);
        return parent[x] = root;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, l, p, q, r, s;
    cin >> n >> k >> l;
    DisjointSet road(n);
    for (int i = 0; i < k; i++) {
        cin >> p >> q;
        road.Unite(p, q);
    }
    DisjointSet railway(n);
    for (int i = 0; i < l; i++) {
        cin >> r >> s;
        railway.Unite(r, s);
    }
    for (int i = 1; i <= n; i++) {
        road.FindRoot(i);
        railway.FindRoot(i);
    }
    map<pair<int, int>, int> connect;
    for (int i = 1; i <= n; i++) {
        connect[{ road.parent[i], railway.parent[i] }] += 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << connect[{ road.parent[i], railway.parent[i] }] << " ";
    }
    cout << endl;
    return 0;
}