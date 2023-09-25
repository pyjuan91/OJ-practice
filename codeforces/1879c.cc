#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int factorial[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	factorial[0] = 1;
	for (int i = 1; i < 200005; i++)
		factorial[i] = (factorial[i - 1] * i) % mod;
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int cnt = 0, len = s.length(), ans2 = 1;
		if (len == 1) {
			cout << "0 1\n";
			continue;
		}
		for (int i = 1; i < len; i++) {
			if (s[i] == s[i - 1]) {
				int j = i;
				while (j < len && s[j] == s[j - 1]) j++;
				cnt += j - i;
				ans2 = (ans2 * (j - i + 1)) % mod;
				i = j;
			}
		}
		ans2 = (ans2 * factorial[cnt]) % mod;
		cout << cnt << ' ' << ans2 << '\n';
	}
	return 0;
}
