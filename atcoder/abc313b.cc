#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	int in[55] = {}, out[55] = {};
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		in[b]++;
		out[a]++;
	}
	int res = -1;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0 && out[i] > 0) {
			if (res != -1) {
				cout << -1;
				return 0;
			}
			res = i;
		}
	}
	cout << res;
	return 0;
}
