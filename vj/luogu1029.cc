#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int x, int y)
{
    int pq = x * y;
    // x = gcd(p, q)
    // y = lcm(p, q)
    if (y % x != 0)
    {
        return 0;
    }
    // p = x * a
    // q = x * b
    // gcd(a, b) = 1
    // y = x * a * b
    // b = y / (x * a)
    int ab = y / x;
    int res = 0;
    for (int i = 1; i * i <= ab; ++i)
    {
        if (ab % i == 0)
        {
            int a = i;
            int b = ab / i;
            if (gcd(a, b) == 1)
            {
                res += 2;
                if (a * a == ab)
                {
                    --res;
                }
            }
        }
    }
    return res;
}
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    cout << patty(x, y) << "\n";
    return 0;
}
