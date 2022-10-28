#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, c, x, y, cnst = 0, xc = 0;
    cin >> n >> c;
    vector<ll> xp;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cnst += pow(llabs(c - y), 2);
        xc += 2 * x;
        xp.push_back(x);
    }
    double p = (double)xc / (2 * n), prefix = 0.0;
    for (ll& i : xp) {
        prefix += pow(fabs(p - (double)i), 2);
    }
    prefix += (double)cnst;
    printf("%.15lf\n", prefix);
    return 0;
}