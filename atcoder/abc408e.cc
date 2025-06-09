#include <atcoder/dsu>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    for (auto &[u, v, w] : edges)
    {
        cin >> u >> v >> w;
    }
    debug(edges);
    int res = 0;
    for (int i = 31; i >= 0; i--)
    {
        auto d = atcoder::dsu(n + 1);
        for (const auto &[u, v, w] : edges)
        {
            if (((w | res) >> i) > (res >> i))
                continue;
            d.merge(u, v);
        }
        if (!d.same(1, n))
            res |= (1 << i);
    }
    cout << res << "\n";
    return 0;
}
