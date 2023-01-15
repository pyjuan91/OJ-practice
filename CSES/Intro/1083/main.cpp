#include "bits/stdc++.h"

using namespace std;
const int maxn = 2e5 + 5;
bool exist[maxn];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, i;
    cin >> n;
    for (i = 1; i < n; i++) {
        cin >> x;
        exist[x] = true;
    }
    for (i = 1; i <= n; i++) if (exist[i] == false) break;
    cout << i;
    return 0;
}
