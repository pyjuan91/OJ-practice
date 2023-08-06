#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		if (n == 1) cout << "NO\n";
		else {
			int quota = 0, one_cnt = 0;
			for (auto x : a) {
				if (x == 1) one_cnt++;
				else quota += x - 1;
			}
			if (quota >= one_cnt) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
