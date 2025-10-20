#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 1; i <= n; i++)
        {
            g[0].push_back({ i, a[i] });
            g[i].push_back({ 0, a[i] });

            if (i > 1)
            {
                g[i].push_back({ i - 1, llabs(a[i] - a[i - 1]) });
                g[i - 1].push_back({ i, llabs(a[i] - a[i - 1]) });
            }

            if (i < n)
            {
                g[i].push_back({ i + 1, llabs(a[i] - a[i + 1]) });
                g[i + 1].push_back({ i, llabs(a[i] - a[i + 1]) });
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> vis(n + 1, false);

        pq.push({ 0, 0 });
        int max_edge = 0;

        while (!pq.empty())
        {
            auto [cost, u] = pq.top();
            pq.pop();

            if (vis[u])
                continue;
            vis[u] = true;
            max_edge = max(max_edge, cost);

            for (auto [v, w] : g[u])
            {
                if (!vis[v])
                {
                    pq.push({ w, v });
                }
            }
        }

        cout << "Case #" << kase << ": " << max_edge << "\n";
    }
    return 0;
}
