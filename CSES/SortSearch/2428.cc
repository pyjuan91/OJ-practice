#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, res = 0, pi = 0, tc = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	map<int, int> m;
	for (auto& x : a) {
		m[x] += 1;
		tc += 1;
		while (m.size() > (size_t) k) {
			m[a[pi]] -= 1;
			if (m[a[pi]] == 0) m.erase(a[pi]);
			pi += 1;
			tc -= 1;
		}
		res += tc;
	}
	cout << res;
	return 0;
}