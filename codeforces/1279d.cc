#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int MOD = 998244353;
int num_of_kids_who_want_gift_i[maxn];
int recored_mod_inv[maxn];
int fast_power(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, k, res = 0;
	cin >> n;
	vector<vector<int>> preferable_gifts;
	for (int i = 0; i < n; i++) {
		cin >> k;
		vector<int> current(k);
		for (auto &x : current) {
			cin >> x;
			num_of_kids_who_want_gift_i[x] += 1;
		}
		preferable_gifts.emplace_back(current);
	}
    
	recored_mod_inv[n] = fast_power(n, MOD - 2, MOD);
	for (int i = 0; i < n; i++) {
		int sz = preferable_gifts[i].size();
		for (int j = 0; j < sz; j++) {
			// 1/n * 1/size * num/n
			if (recored_mod_inv[sz] == 0)
				recored_mod_inv[sz] = fast_power(sz, MOD - 2, MOD);
			res += recored_mod_inv[n] * recored_mod_inv[sz] % MOD
				 * num_of_kids_who_want_gift_i[preferable_gifts[i][j]]
				 % MOD * recored_mod_inv[n] % MOD;
			res %= MOD;
		}
	}
	cout << res;
	return 0;
}