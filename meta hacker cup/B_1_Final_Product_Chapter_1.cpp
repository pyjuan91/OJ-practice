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
    int t, n, a, b;
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        cin >> n >> a >> b;
        cout << "Case #" << kase << ":";

        for (int i = 1; i < 2 * n; i++)
            cout << " 1";
        cout << " " << b << "\n";
    }
    return 0;
}
