#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, su = 0, res = 0, resu = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x, su += x;
    sort(a.rbegin(), a.rend());
    for (auto x : a) {
        resu += x, res += 1;
        if (resu > su - resu)
            break;
    }
    cout << res;
    return 0;
}
