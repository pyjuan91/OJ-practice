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
    int n;
    array<array<int, 2>, 3> a;
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> a[i][0] >> a[i][1];
    debug(a);

    int res = INT64_MAX;
    for (int i = 0; i < 3; i++)
    {
        int req = (n / a[i][0] + (n % a[i][0] != 0)) * a[i][1];
        res = min(res, req);
    }

    cout << res << "\n";
    return 0;
}
