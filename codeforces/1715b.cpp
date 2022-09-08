#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(void)
{
    ll t, n, k, b, s;
    cin >> t;
    while (t--) {
        cin >> n >> k >> b >> s;
        if (k * b < s - n * k + n || s < k * b) {
            cout << "-1\n";
            continue;
        }
        vector<ll> v(n);
        for (int i = 0; i < n - 1; i++)
            v[i] = 0;
        v[n - 1] = s;
        ll cur = s / k, emptyHole = n - 1;
        if (cur < b) {
            cout << "-1\n";
            continue;
        }

        while (cur > b && emptyHole) {
            v[emptyHole - 1] = k - 1;
            emptyHole--;
            v[n - 1] -= k - 1;
            cur = v[n - 1] / k;
        }
        if (cur != b) {
            cout << "-1\n";
            continue;
        }
        bool first = true;
        for (ll& i : v) {
            if (first)
                first = false;
            else
                cout << " ";
            cout << i;
        }
        cout << "\n";
    }

    return 0;
}