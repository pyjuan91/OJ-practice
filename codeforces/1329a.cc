#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, su = 0, cur;
	cin >> n >> m;
	vector<int> l(m);
	for (auto& x : l) cin >> x, su += x;
	if (su < n) {
		cout << "-1\n";
		return 0;
	}
	vector<int> res;
	for (int i = m - 1; i >= 0; i--) {
		if (i == m - 1) {
			res.emplace_back(n - l[i] + 1);
			cur = res.back();
		}
		else {
			if (cur + l[i] - 2 > n)
				res.emplace_back(n - l[i] + 1);
			else res.emplace_back(cur - 1);
			cur = res.back();
		}
	}
	reverse(res.begin(), res.end());
	cur = 0;
	for (int i = 0; i < m; i++) {
		int ideal = cur + 1;
		if (res[i] < ideal) {
			cout << "-1\n";
			return 0;
		}
		res[i] = ideal;
		if (i + 1 < m && res[i] + l[i] >= res[i + 1]) break;
		cur = res[i] + l[i] - 1;
	}
	for (auto& x : res) cout << x << ' ';
	cout << '\n';
	return 0;
}
