#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, res, x, n;
    cin >> t;
    while (t--) {
        res = 0;
        cin >> n;
        while (n--) {
            cin >> x;
            res += x % 2;
        }
        cout << res << "\n";
    }
    return 0;
}