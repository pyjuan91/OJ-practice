#include <bits/stdc++.h>
#include <atcoder/segtree>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int op(int a, int b) { return a + b; }
int e() { return 0; }
const int kMax = 1e6;
atcoder::segtree<int, op, e> seg(kMax + 1);

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + (s[i - 1] == '0' ? 1 : -3);
    }

    int minimum = *min_element(prefix.begin(), prefix.end());
    for (auto& i : prefix) i -= minimum, i += 1;

    debug(prefix);

    int res = 0;
    seg.set(prefix[0], 1);
    for (int r = 1; r <= n; r++) {
        debug(r, prefix[r]);
        res += seg.prod(0, prefix[r] - 1);
        res += seg.prod(prefix[r] + 1, prefix[r] + 2);
        seg.set(prefix[r], seg.get(prefix[r]) + 1);
    }

    cout << res << '\n';
    return 0;
}
