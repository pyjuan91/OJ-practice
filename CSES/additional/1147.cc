#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, res = 0;
	cin >> n >> m;
	vector<vector<char>> f(n, vector<char>(m));
	vector<queue<int>> t(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> f[i][j];
			if (f[i][j] == '*') t[j].push(i);
		}
	}
	for (int j = 0; j < m; j++) t[j].push(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			while (!t[j].empty() && t[j].front() < i)
				t[j].pop();
		stack<pair<int, int>> s;
		for (int j = 0; j < m; j++) {
			auto height = t[j].front() - i, start = j;
			while (!s.empty() && height < s.top().first) {
				res = max(res, s.top().first * (j - s.top().second));
				start = s.top().second;
				s.pop();
			}
			s.push(make_pair(height, start));
		}
		while (!s.empty()) {
			res = max(res, (m - s.top().second) * s.top().first);
			s.pop();
		}
	}
	cout << res << "\n";
	return 0;
}