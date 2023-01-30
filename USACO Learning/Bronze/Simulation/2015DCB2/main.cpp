#include "bits/stdc++.h"

using namespace std;

int main(void) {
    ::freopen("speeding.in", "r", stdin);
    ::freopen("speeding.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, sum = 0, cur, i1, i2, speed;
    long long res = 0LL;
    cin >> n >> m;
    vector<pair<int, long long>> a, b;
    for (int i = 0; i < n; i++) {
        cin >> cur >> speed;
        sum += cur;
        a.emplace_back(make_pair(sum, speed));
    }
    sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> cur >> speed;
        sum += cur;
        b.emplace_back(make_pair(sum, speed));
    }
    i1 = i2 = 0;
    while (i1 < n && i2 < m) {
        res = max(res, b[i2].second - a[i1].second);
        if (b[i2].first == a[i1].first) i2++, i1++;
        else if (b[i2].first > a[i1].first) i1++;
        else i2++;
    }
    cout << res;
    return 0;
}