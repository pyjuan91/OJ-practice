#include <bits/stdc++.h>
using namespace std;
long long fast_power(long long a, long long b, long long mod)
{
    long long ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
pair<long long, long long> extgcd(long long a, long long b)
{
    if (b == 0)
        return { 1LL, 0LL };
    auto [xp, yp] = extgcd(b, a % b);
    return { yp, xp - a / b * yp };
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        long long r[3], k[3];
        long long res = 0;
        for (int i = 0; i < 3; i++)
            cin >> k[i] >> r[i];
        long long bigM = k[0] * k[1] * k[2];
        // cout << "BIG M: " << bigM << endl;
        for (int i = 0; i < 3; i++) {
            long long smallM = bigM / k[i];
            // cout << "SMALL M: " << smallM << endl;
            // cout << smallM % k[i] << endl;
            if (smallM % k[i] == 1) {
                res += (r[i] * smallM) % bigM;
                res %= bigM;
            } else {
                auto [_x, _y] = extgcd(smallM, k[i]);
                res += (r[i] * _x * smallM) % bigM;
                // cout << "i: " << i << " " << _x * smallM << " " << (_x * smallM) % k[i] << endl;
                res %= bigM;
            }
        }
        while (res < 0)
            res += bigM;
        cout << res << "\n";
    }
    return 0;
}