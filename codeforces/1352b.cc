#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n, int k)
{
    if(n % 2 == 0)
    {
        if(k % 2 == 0)
        {
            if(k > n)
            {
                cout << "NO\n";
                return;
            }
            cout << "YES\n";
            for(int i = 1; i < k; i++)
                cout << "1 ";
            cout << n - k + 1 << "\n";
            return;
        }
        if(2 * k > n)
        {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for(int i = 1; i < k; i++)
            cout << "2 ";
        cout << n - 2 * (k - 1) << "\n";
        return;
    }

    if(k % 2 == 0 or k > n)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i < k; i++)
        cout << "1 ";
    cout << n - k + 1 << "\n";
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        patty(n, k);
    }
    return 0;
}
