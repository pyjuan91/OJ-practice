#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	ifstream cin("planting.in");
	ofstream cout("planting.out");
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	if (n <= 3) {
		cout << n << "\n";
		return 0;
	}
	int ma = INT32_MIN;
	for (int i = 1; i <= n; i++) {
		ma = max(ma, (int) g[i].size());
	}
	cout << ma + 1 << "\n";
	return 0;
}
