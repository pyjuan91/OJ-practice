#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> parent;
    int find_root(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find_root(parent[x]);
    }
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    bool isInSameUnion(int a, int b)
    {
        return find_root(a) == find_root(b);
    }
    void Unite(int a, int b)
    {
        parent[find_root(a)] = find_root(b);
    }
};
class Edge {
public:
    int a, b, c;
    Edge()
    {
        a = 0, b = 0, c = 0;
    }
    Edge(int _a, int _b, int _c)
    {
        a = _a, b = _b, c = _c;
    }
    bool operator<(const Edge& other) const
    {
        return c < other.c;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b, c, cnt = 0;
    long long res = 0;
    cin >> n >> m;
    vector<Edge> e;
    while (m--) {
        cin >> a >> b >> c;
        e.emplace_back(Edge(a, b, c));
    }
    sort(e.rbegin(), e.rend());
    DisjointSet ds(n);
    while (!e.empty()) {
        Edge cur = e.back();
        e.pop_back();

        if (ds.isInSameUnion(cur.a, cur.b))
            continue;

        ds.Unite(cur.a, cur.b);
        cnt += 1;
        res += 1LL * cur.c;

        if (cnt == n - 1)
            break;
    }
    if (cnt == n - 1)
        cout << res << "\n";
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}