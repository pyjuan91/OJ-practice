#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> a(n);
		for (auto& x : a) cin >> x;
		int pos = 1, consider = 0;
		while (k--) {
			while (consider < n && a[consider] <= pos + consider)
				consider++;
			pos += consider;
		}
		cout << pos << "\n";
	}
	return 0;
}
