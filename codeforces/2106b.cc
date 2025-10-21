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
    int t, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (int i = 0; i < x; i++)
            cout << i << " ";
        for (int i = x + 1; i < n; i++)
            cout << i << " ";
        if (x < n)
            cout << x;
        cout << "\n";
    }
    return 0;
}
