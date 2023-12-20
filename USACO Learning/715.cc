#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	ifstream cin("maxcross.in");
	ofstream cout("maxcross.out");
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, b, x, res = INT32_MAX, sliding_sum = 0;
	cin >> n >> k >> b;
	vector<bool> signals(n + 1, true);
	while (b--) cin >> x, signals[x] = false;
	for (int i = 1; i < k; i++) sliding_sum += !signals[i];
	for (int i = k; i <= n; i++) {
		sliding_sum += !signals[i];
		sliding_sum -= !signals[i - k];
		res = min(res, sliding_sum);
	}
	cout << res << '\n';
	return 0;
}
