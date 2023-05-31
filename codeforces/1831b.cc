#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int n, vector<int>& a, vector<int>& b) {
	vector<int> longest_a(2 * n + 1), longest_b(2 * n + 1);
	for (int i = 0; i < n; i++) {
		int same = 1;
		while (i + 1 < n && a[i] == a[i + 1]) {
			i += 1;
			same += 1;
		}
		longest_a[a[i]] = max(longest_a[a[i]], same);
	}
	for (int i = 0; i < n; i++) {
		int same = 1;
		while (i + 1 < n && b[i] == b[i + 1]) {
			i += 1;
			same += 1;
		}
		longest_b[b[i]] = max(longest_b[b[i]], same);
	}
	int res = 0;
	for (int i = 1; i <= 2 * n; i++)
		res = max(res, longest_a[i] + longest_b[i]);
	return res;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		cout << chaewon(n, a, b) << "\n";
	}
	return 0;
}