#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, c, res = 0;
	cin >> n >> m >> c;
	vector<int> b(m);
	for (auto& x : b) cin >> x;
	for (int i = 0; i < n; i++) {
		int sum = c;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			sum += a * b[j];
		}
		if (sum > 0) res++;
	}
	cout << res << '\n';
	return 0;
}
