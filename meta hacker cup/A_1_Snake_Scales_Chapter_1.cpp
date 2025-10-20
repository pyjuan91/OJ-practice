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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            res = max(res, llabs(a[i] - a[i - 1]));
        }
        cout << "Case #" << kase << ": " << res << "\n";
    }
    return 0;
}
