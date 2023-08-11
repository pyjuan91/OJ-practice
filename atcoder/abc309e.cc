#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int n, m, x, d, p[maxn] = {}, deep[maxn] = {}, res = 0;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 2; i <= n; i++) cin >> p[i];
	for (int i = 0; i < m; i++) {
		cin >> x >> d;
		deep[x] = max(deep[x], d + 1);
	}
	for (int i = 1; i <= n; i++) {
		deep[i] = max(deep[i], deep[p[i]] - 1);
	}
	for (int i = 1; i <= n; i++) res += deep[i] > 0;
    cout << res << '\n';
	return 0;
}
