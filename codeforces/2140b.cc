#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int x)
{
    // (10*x + y) % (x + y) == 0
    // 10*x + y == k*x + k*y
    // (10 - k)*x == (k - 1)*y
    // y == 8*x
    return 8 * x;
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        cout << patty(x) << "\n";
    }
    return 0;
}
