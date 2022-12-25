#include <bits/stdc++.h>
#define IO std::ios_base::sync_with_stdio(false);
#define ll long long
using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}

int main()
{
    IO;
    int T = 1;
    cin >> T;
    while (T--) {
        ll n, m, x, y, vx, vy;
        cin >> n >> m >> x >> y >> vx >> vy;
        if (vx == 0) {
            if (x == 0 || x == n)
                cout << x << " " << (vy == 1) * m << '\n';
            else
                cout << -1 << '\n';
            continue;
        }
        if (vy == 0) {
            if (y == 0 || y == m)
                cout << (vx == 1) * n << " " << y << '\n';
            else
                cout << -1 << '\n';
            continue;
        }

        ll c;
        ll x_i = x % n, y_i = y % m;

        if (vx == 1)
            x_i = (n - x) % n;
        if (vy == 1)
            y_i = (m - y) % m;

        c = x_i - y_i;
        ll g = gcd(n, m);
        if (c % g != 0) {
            cout << -1 << '\n';
            continue;
        }
        ll xx, yy;
        exgcd(n, m, xx, yy);
        xx *= (-c / g);
        ll lcm = n / g * m;
        xx %= (m / g);
        ll t = x_i + n * xx;
        t = (t % lcm + lcm) % lcm;

        x += t * vx;
        y += t * vy;

        ll nn = n + n, mm = m + m;
        cout << (x % nn + nn) % nn << " " << (y % mm + mm) % mm << '\n';
    }
}