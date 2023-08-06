#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	vector<pii> mons;
	pii person;
	for (auto &i : g) cin >> i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'A') person = mp(i, j);
			if (g[i][j] == 'M') mons.push_back(mp(i, j));
		}
	}

	queue<vector<int>> q;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	for (auto p : mons) {
		q.push(vector<int> {p.first, p.second, 1});
		vis[p.first][p.second] = true;
	}
	q.push(vector<int> {person.first, person.second, 0});
	vis[person.first][person.second] = true;

	const pii dir[4] = {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)};
	vector<vector<int>> rec(n, vector<int>(m, 0));

	auto is_entries = [&](auto node) {
		return node.first == 0 || node.first == n - 1
			|| node.second == 0 || node.second == m - 1;
	};

	if (is_entries(person)) {
		cout << "YES\n0\n";
		return 0;
	}

	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		auto cur_node = mp(v[0], v[1]);
		auto cur_type = v[2];
		for (int i = 0; i < 4; i++) {
			auto next_node = mp(
			  cur_node.first + dir[i].first,
			  cur_node.second + dir[i].second);
			if (
			  next_node.first < 0 || next_node.first >= n
			  || next_node.second < 0 || next_node.second >= m)
				continue;
			if (g[next_node.first][next_node.second] == '#')
				continue;
			if (vis[next_node.first][next_node.second])
				continue;
			vis[next_node.first][next_node.second] = true;
			rec[next_node.first][next_node.second] = i;
			if (cur_type == 0 && is_entries(next_node)) {
				cout << "YES\n";
				string ans = "";
				while (next_node != person) {
					int i = rec[next_node.first][next_node.second];
					ans += "RLDU"[i];
					next_node.first -= dir[i].first;
					next_node.second -= dir[i].second;
				}
				reverse(ans.begin(), ans.end());
				cout << ans.size() << '\n';
				cout << ans << '\n';
				return 0;
			}
			q.push(vector<int> {next_node.first, next_node.second, cur_type});
		}
	}
	cout << "NO\n";
	return 0;
}
