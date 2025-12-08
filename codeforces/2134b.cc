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
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<int> a(n);
        for(auto& x : a)
            cin >> x;
        for(auto& x : a)
        {
            x += k * (x % (k + 1));
        }
        for(const auto& x : a)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
