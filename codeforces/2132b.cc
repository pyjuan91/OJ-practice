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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> res;
        for (int i = 10; i <= n; i *= 10)
        {
            if (n % (i + 1) == 0)
                res.push_back(n / (i + 1));
        }
        sort(res.begin(), res.end());
        cout << res.size() << "\n";
        for (auto& x : res)
            cout << x << " ";
        if (!res.empty())
            cout << "\n";
    }
    return 0;
}
