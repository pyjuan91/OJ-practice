#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x;
	string s, res;
	cin >> n >> m >> s;
	vector<vector<int>> a(m);
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x - 1].emplace_back(i);
	}
	res = s;
	for (int i = 0; i < m; i++) {
		if (a[i].size() == 1) continue;
		for (int j = 1; j < (int) a[i].size(); j++)
			res[a[i][j]] = s[a[i][j - 1]];
		res[a[i][0]] = s[a[i].back()];
	}
    cout << res << "\n";
	return 0;
}
