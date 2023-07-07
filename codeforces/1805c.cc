#include <bits/stdc++.h>
#define int long long
using namespace std;
void chaewon(vector<int> &k, int a, int b, int c) {
	if (c <= 0) {
		cout << "NO\n";
		return;
	}
	auto x = lower_bound(k.begin(), k.end(), b);
	if (x != k.end() && pow(*x - b, 2) < 4 * a * c)
		cout << "YES\n" << *x << "\n";
	else if (x != k.begin() && pow(*(--x) - b, 2) < 4 * a * c)
		cout << "YES\n" << *x << "\n";
	else cout << "NO\n";
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b, c;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> k(n);
		for (auto &x : k) cin >> x;
		sort(k.begin(), k.end());
		while (m--) {
			cin >> a >> b >> c;
			chaewon(k, a, b, c);
		}
		cout << "\n";
	}
	return 0;
}