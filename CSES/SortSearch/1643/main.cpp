#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
#define int long long
    int n, x, cur = INTMAX_MIN, res = INTMAX_MIN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (cur < 0) cur = x;
        else cur += x;
        res = max(cur, res);
    }
    cout << res;
    return 0;
}