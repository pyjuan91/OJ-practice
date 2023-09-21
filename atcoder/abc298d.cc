#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int t, op, x, ten_pow[600005], ans = 1;
deque<int> nu = {1};
int fast_power(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}
void init() {
	ten_pow[0] = 1;
	for (int i = 1; i <= 600000; i++)
		ten_pow[i] = ten_pow[i - 1] * 10 % mod;
}
int32_t main() {
	init();
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			nu.push_back(x);
			ans = ans * 10 + x;
			ans %= mod;
		}
		else if (op == 2) {
			ans = (ans + mod - ((nu.front() * ten_pow[nu.size() - 1]) % mod))
				% mod;
			nu.pop_front();
		}
		else cout << ans << "\n";
	}
	return 0;
}
