#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int con_mi[maxn], con_ma[maxn], pre_mi[maxn], pre_ma[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, u, v, k, nc;
	char op;
	cin >> t;
	while (t--) {
		cin >> n;
		nc = 2;

		con_mi[1] = con_ma[1] = pre_ma[1] = 1;
		pre_mi[1] = 0;

		while (n--) {
			cin >> op;
			if (op == '+') {
				cin >> u >> k;
				if (k == 1) {
					pre_mi[nc] = pre_mi[u];
					pre_ma[nc] = max({pre_ma[u], con_ma[u] + 1, 1});
					con_mi[nc] = min(con_mi[u] + 1, 1);
					con_ma[nc] = max(con_ma[u] + 1, 1);
				}
				else {
					pre_mi[nc] = min({pre_mi[u], con_mi[u] - 1, -1});
					pre_ma[nc] = pre_ma[u];
					con_mi[nc] = min(con_mi[u] - 1, -1);
					con_ma[nc] = max(con_ma[u] - 1, -1);
				}
				nc++;
			}
			else {
				cin >> u >> v >> k;
				if (k >= pre_mi[v] && k <= pre_ma[v])
					cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}