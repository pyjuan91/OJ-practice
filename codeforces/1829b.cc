#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, res;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		res = 0;
		for (auto& x : a) cin >> x;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				int j = i;
				while (j < n && a[j] == 0) j += 1;
				res = max(res, j - i);
				i = j - 1;
			}
		}
		cout << res << "\n";
	}
	return 0;
}