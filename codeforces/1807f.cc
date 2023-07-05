#include <bits/stdc++.h>
#define int long long
using namespace std;
const pair<int, int> d[4] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
void chaewon(
  int n, int m, int x1, int x2, int y1, int y2, int cd,
  vector<vector<vector<bool>>> &vist, int &sol, bool done = false) {
	// cout << x1 << " " << y1 << endl;
	if (done) return;
	if (
	  (x2 - x1) / d[cd].first >= 0
	  && (x2 - x1) / d[cd].first == (y2 - y1) / d[cd].second) {
		done = true;
		return;
	}
	if (vist[x1][y1][cd]) {
		sol = -1;
		done = true;
		return;
	}
	vist[x1][y1][cd] = true;
	sol += 1;
	switch (cd) {
		case 0:
			if (m - y1 == x1 - 1)
				chaewon(n, m, 1, x2, m, y2, 2, vist, sol, done);
			else if (m - y1 > x1 - 1)
				chaewon(n, m, 1, x2, y1 + x1 - 1, y2, 1, vist, sol, done);
			else
				chaewon(n, m, x1 - m + y1, x2, m, y2, 3, vist, sol, done);
			break;
		case 1:
			if (m - y1 == n - x1)
				chaewon(n, m, n, x2, m, y2, 3, vist, sol, done);
			else if (m - y1 > n - x1)
				chaewon(n, m, n, x2, y1 + n - x1, y2, 0, vist, sol, done);
			else
				chaewon(n, m, x1 + m - y1, x2, m, y2, 2, vist, sol, done);
			break;
		case 2:
			if (y1 - 1 == n - x1)
				chaewon(n, m, n, x2, 1, y2, 0, vist, sol, done);
			else if (y1 - 1 > n - x1)
				chaewon(n, m, n, x2, y1 - n + x1, y2, 3, vist, sol, done);
			else
				chaewon(n, m, x1 + y1 - 1, x2, 1, y2, 1, vist, sol, done);
			break;
		default:
			if (y1 - 1 == x1 - 1)
				chaewon(n, m, 1, x2, 1, y2, 1, vist, sol, done);
			else if (y1 - 1 > x1 - 1)
				chaewon(n, m, 1, x2, y1 - x1 + 1, y2, 2, vist, sol, done);
			else
				chaewon(n, m, x1 - y1 + 1, x2, 1, y2, 0, vist, sol, done);
			break;
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, x1, x2, y1, y2, cd;
	string sd;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> sd;
		if (sd == "UR") cd = 0;
		else if (sd == "DR") cd = 1;
		else if (sd == "DL") cd = 2;
		else cd = 3;
		auto vist = vector<vector<vector<bool>>>(
		  n + 1, vector<vector<bool>>(m + 1, vector<bool>(4, false)));
		int sol = 0;
		chaewon(n, m, x1, x2, y1, y2, cd, vist, sol);
		cout << sol << "\n";
	}
	return 0;
}