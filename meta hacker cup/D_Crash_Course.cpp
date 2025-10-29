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
	int t, n;
	string s;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> n >> s;
		bool alice_win = false;
		int cnt[2] = {};
		for (int i = n - 1; i >= 0; i--) {
			cnt[s[i] - 'A']++;
			if (cnt[0] > cnt[1]) {
				alice_win = true;
			}
		}
		cout << "Case #" << kase << ": " << (alice_win ? "Alice" : "Bob") << "\n";
	}
	return 0;
}
