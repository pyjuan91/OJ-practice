#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e14 + 5;
vector<ll> dijkstra(const vector<vector<pair<int, int>>>& g, int start)
{
    int n = g.size();
    vector<ll> d(n, INF);
    vector<bool> used(n, false);
    using QP = pair<long long, int>;
    priority_queue<QP, vector<QP>, greater<QP>> prique;
    d[start] = 0;
    prique.push(make_pair(d[start], start));
    while (!prique.empty()) {
        int st = prique.top().second;
        prique.pop();
        if (used[st])
            continue;
        used[st] = true;
        for (auto [en, cost] : g[st]) {
            if (d[en] > d[st] + cost) {
                d[en] = d[st] + cost;
                prique.push(make_pair(d[en], en));
            }
        }
    }
    return d;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph;
    graph.resize(n + 1);
    while (m--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b, c));
    }
    vector<ll> ans = dijkstra(graph, 1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}