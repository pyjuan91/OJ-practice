#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int const kMax = 1e6 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

int init = []()
{
    for (int i = 2; i <= kMax; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= kMax; ++j)
        {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])
            {
                break;
            }
        }
    }
    return 0;
}();

void patty(int n)
{
    vector<int> res(n + 1, 0);
    auto it = upper_bound(pr.begin(), pr.end(), n);
    it = prev(it);
    for (;;)
    {
        vector<int> cycle;
        int x = *it;
        while (x <= n)
        {
            if (res[x] == 0)
            {
                cycle.push_back(x);
            }
            x += *it;
        }
        debug(cycle);
        int m = cycle.size();
        for (int i = 0; i < m; i++)
        {
            res[cycle[i]] = cycle[(i + 1) % m];
        }
        if (it == pr.begin())
        {
            break;
        }
        it = prev(it);
    }
    debug(res);
    for (int i = 1; i <= n; i++)
    {
        if (res[i] == 0)
        {
            res[i] = i;
        }
        cout << res[i] << " ";
    }
    cout << "\n";
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        patty(n);
    }
    return 0;
}
