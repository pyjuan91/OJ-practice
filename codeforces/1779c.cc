#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int& n, int& m, vector<int>& a) {
	int res = 0, prefix_sum = 0;
	priority_queue<int> pq;
	for (int i = m + 1; i <= n; i++) {
		prefix_sum += a[i];
		if (a[i] < 0) pq.push(-2 * a[i]);
		if (prefix_sum < 0) {
			prefix_sum += pq.top();
			pq.pop();
			res += 1;
		}
	}
	while (!pq.empty()) pq.pop();
	prefix_sum = 0;
	for (int i = m; i > 1; i--) {
		prefix_sum += a[i];
		if (a[i] > 0) pq.push(2 * a[i]);
		if (prefix_sum > 0) {
			prefix_sum -= pq.top();
			pq.pop();
			res += 1;
		}
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << chaewon(n, m, a) << '\n';
	}
	return 0;
}