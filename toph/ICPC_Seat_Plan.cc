#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, res = 0, x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x == 0) res++;
		}
	}
	cout << res << '\n';
	return 0;
}
