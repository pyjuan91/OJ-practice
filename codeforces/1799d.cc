#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], t, n, m, x;
unordered_map<int, int> quota;
bool chaewon() {
	stack<int> mono;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) return false;
		while (!mono.empty() && mono.top() < b[i]) mono.pop();
		if (a[i] > b[i]) {
			if (!mono.empty() && mono.top() == b[i]) continue;
			quota[b[i]] -= 1;
			mono.push(b[i]);
			if (quota[b[i]] < 0) return false;
		}
	}
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		quota.clear();
		cin >> m;
		while (m--) cin >> x, quota[x] += 1;
		if (chaewon()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}