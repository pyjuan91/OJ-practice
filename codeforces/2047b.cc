#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n)
{
    for (int i = n; i >= 1; i--)
        cout << i << " ";
    cout << n;
    for (int i = 1; i < n; i++)
        cout << " " << i;
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
