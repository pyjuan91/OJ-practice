#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, res;
	string s;
	cin >> t;
	while (t--) {
		res = 0;
		cin >> n >> m >> s;
		string ans(n, '.');
		if (m == 0) cout << n << '\n' << s << '\n';
		else {
			vector<int> g, h;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'G') g.emplace_back(i);
				else if (s[i] == 'H') h.emplace_back(i);
			}
			if (!g.empty()) {
				int index = 0, pos = min(g[0] + m, n - 1);
				while ((size_t) index < g.size()) {
					while ((size_t) index < g.size()) {
						if (g[index] > pos + m) break;
						index++;
					}
					res++;
					ans[pos] = 'G';
					pos = min(g[index] + m, n - 1);
				}
			}
			if (!h.empty()) {
				int index = 0, pos = min(h[0] + m, n - 1);
				while (ans[pos] != '.') pos--;
				while ((size_t) index < h.size()) {
					while ((size_t) index < h.size()) {
						if (h[index] > pos + m) break;
						index++;
					}
					res++;
					ans[pos] = 'H';
					pos = min(h[index] + m, n - 1);
					while (ans[pos] != '.') pos--;
				}
			}
            cout << res << '\n' << ans << '\n';
		}
	}
	return 0;
}
