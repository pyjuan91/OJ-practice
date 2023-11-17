#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	string s;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>> g(n + 1);
		for (int i = 2; i <= n; i++) {
			cin >> x;
			g[x].push_back(i);
			g[i].push_back(x);
		}
		cin >> s;
		vector<int> c(n + 1), black(n + 1, -1), white(n + 1, -1);
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == 'W') c[i] = 1;
			else c[i] = 0;
		}
		function<void(int, int)> get_black = [&](int u, int p) {
			int res = 0;
			for (int v : g[u]) {
				if (v == p) continue;
				get_black(v, u);
				res += black[v];
			}
			if (c[u] == 0) res++;
			black[u] = res;
		};
		function<void(int, int)> get_white = [&](int u, int p) {
			int res = 0;
			for (int v : g[u]) {
				if (v == p) continue;
				get_white(v, u);
				res += white[v];
			}
			if (c[u] == 1) res++;
			white[u] = res;
		};
		get_black(1, 0);
		get_white(1, 0);
		// for (int i = 1; i <= n; i++) cout << black[i] << ' ';
		// cout << '\n';
		// for (int i = 1; i <= n; i++) cout << white[i] << ' ';
		// cout << '\n';
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (black[i] == white[i]) res++;
		}
		cout << res << '\n';
	}
	return 0;
}
