#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    vector<ll> sum(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0)
            sum[i] = a[i];
        else
            sum[i] = sum[i - 1] + a[i];
    }
    t %= sum[n - 1];
    for (ll i = 0; i < n; i++) {
        if (sum[i] >= t) {
            cout << i + 1 << " ";
            if (i == 0)
                cout << t;
            else
                cout << t - sum[i - 1];
            cout << endl;
            return 0;
        }
    }
    return 0;
}