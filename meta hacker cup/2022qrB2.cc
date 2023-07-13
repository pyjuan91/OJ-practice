#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int count_friend(int r, int c, vector<string> &g, int x, int y) {
	int res = 0;
	if (x + 1 < r && g[x + 1][y] != '#') res++;
	if (y + 1 < c && g[x][y + 1] != '#') res++;
	if (x - 1 >= 0 && g[x - 1][y] != '#') res++;
	if (y - 1 >= 0 && g[x][y - 1] != '#') res++;
	return res;
}
bool update_friend(
  int r, int c, vector<string> &g, vector<vector<int>> &fc,
  int x, int y, queue<pii> &q, vector<vector<bool>> &done) {
	if (x + 1 < r && !done[x + 1][y]) {
		fc[x + 1][y]--;
		if (fc[x + 1][y] == 0 || fc[x + 1][y] == 1) {
			if (g[x + 1][y] == '^') return false;
			q.push(make_pair(x + 1, y));
			done[x + 1][y] = true;
			g[x + 1][y] = '.';
		}
	}
	if (y + 1 < c && !done[x][y + 1]) {
		fc[x][y + 1]--;
		if (fc[x][y + 1] == 0 || fc[x][y + 1] == 1) {
			if (g[x][y + 1] == '^') return false;
			q.push(make_pair(x, y + 1));
			done[x][y + 1] = true;
			g[x][y + 1] = '.';
		}
	}
	if (x - 1 >= 0 && !done[x - 1][y]) {
		fc[x - 1][y]--;
		if (fc[x - 1][y] == 0 || fc[x - 1][y] == 1) {
			if (g[x - 1][y] == '^') return false;
			q.push(make_pair(x - 1, y));
			done[x - 1][y] = true;
			g[x - 1][y] = '.';
		}
	}
	if (y - 1 >= 0 && !done[x][y - 1]) {
		fc[x][y - 1]--;
		if (fc[x][y - 1] == 0 || fc[x][y - 1] == 1) {
			if (g[x][y - 1] == '^') return false;
			q.push(make_pair(x, y - 1));
			done[x][y - 1] = true;
			g[x][y - 1] = '.';
		}
	}
	return true;
}
bool chaewon(int r, int c, vector<string> &g) {
	vector<vector<int>> fc(r, vector<int>(c));
	vector<vector<bool>> done(r, vector<bool>(c, false));
	queue<pii> rm_pending;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (g[i][j] == '#') fc[i][j] = -1;
			else
				fc[i][j] = count_friend(r, c, g, i, j), g[i][j] = '^';
			if (fc[i][j] == 0 || fc[i][j] == 1)
				rm_pending.push(make_pair(i, j)),
				  done[i][j] = true, g[i][j] = '.';
		}
	}
	while (!rm_pending.empty()) {
		pii cur = rm_pending.front();
		rm_pending.pop();
		if (update_friend(r, c, g, fc, cur.first, cur.second, rm_pending, done))
			continue;
		return false;
	}
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, r, c;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> r >> c;
		vector<string> g(r);
		for (auto &s : g) cin >> s;
		cout << "Case #" << kase << ": ";
		if (!chaewon(r, c, g)) cout << "Impossible\n";
		else {
			cout << "Possible\n";
			for (auto &s : g) cout << s << "\n";
		}
	}
	return 0;
}