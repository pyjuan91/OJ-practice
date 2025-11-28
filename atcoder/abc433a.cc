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
    int x, y, z;
    cin >> x >> y >> z;
    if((x - z * y) % (z - 1) == 0 && (x - z * y) >= 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
