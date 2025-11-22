#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		vector<int> a(n);
		int cnt[3] = {};
		for (auto& x : a) {
			cin >> x;
			cnt[x]++;
		}
		int sum = accumulate(a.begin(), a.end(), 0LL);
		if (sum == s || sum <= s - 2) {
			cout << "-1\n";
		} else {
			for (int i = 0; i < cnt[0]; i++) {
				cout << "0 ";
			}
			for (int i = 0; i < cnt[2]; i++) {
				cout << "2 ";
			}
			for (int i = 0; i < cnt[1]; i++) {
				cout << "1 ";
			}
			cout << "\n";
		}
	}
	return 0;
}
