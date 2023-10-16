#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, c, k, res = 0, ct, rc;
	cin >> n >> c >> k;
	vector<int> t(n);
	for (auto& x : t) cin >> x;
	sort(t.rbegin(), t.rend());
	while (!t.empty()) {
		res++, ct = t.back() + k, rc = 1;
		t.pop_back();
		while (!t.empty() && rc < c && ct >= t.back()) {
			rc++, t.pop_back();
		}
	}
	cout << res;
	return 0;
}
