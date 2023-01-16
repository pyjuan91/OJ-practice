#include "bits/stdc++.h"

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, last, cur;
    cin >> n;
    long long res = 0;
    cin >> last;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        if (cur < last) {
            res += 1LL * (last - cur);
        } else last = cur;
    }
    cout << res;

    return 0;
}