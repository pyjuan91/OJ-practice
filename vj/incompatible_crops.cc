#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, res = 0;
	cin >> n >> m;
	vector<string> v(n);
	for (auto &s : v) cin >> s;
	auto nice = [&](int x, int y) {
		if (x - 1 >= 0 && v[x - 1][y] == '*') return false;
		if (x + 1 < n && v[x + 1][y] == '*') return false;
		if (y - 1 >= 0 && v[x][y - 1] == '*') return false;
		if (y + 1 < m && v[x][y + 1] == '*') return false;
		return true;
	};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			if (v[i][j] == '.' && nice(i, j)) { ++res; }
	}
    cout << res << '\n';
	return 0;
}
