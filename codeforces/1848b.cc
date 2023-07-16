#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, k, last[maxn], x, res;
priority_queue<int> range[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		res = INT32_MAX;
		cin >> n >> k;
		for (int i = 1; i <= k; i++) {
			while (!range[i].empty()) range[i].pop();
			last[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> x;
			range[x].push(i - last[x] - 1);
			last[x] = i;
		}
		for (int i = 1; i <= k; i++) {
			range[i].push(n - last[i]);
			auto hi = range[i].top();
			range[i].pop();
			range[i].push(hi / 2);
			res = min(res, range[i].top());
		}
		cout << res << "\n";
	}
	return 0;
}