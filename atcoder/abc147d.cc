#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> suff(n + 2, vector<int>(64, 0));
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 64; j++)
			suff[i][j] = suff[i + 1][j] + ((a[i] >> j) & 1);
	}
	int res = 0;
	const int mod = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 64; j++) {
			if ((a[i] >> j) & 1) {
				res = (res + (1LL << j) % mod * (n - i - suff[i + 1][j]) % mod)
					% mod;
			}
			else {
				res = (res + (1LL << j) % mod * suff[i + 1][j] % mod) % mod;
			}
		}
	}
	cout << res << '\n';
	return 0;
}
