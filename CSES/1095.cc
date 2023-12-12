#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	const int mod = 1e9 + 7;
	auto fast_power = [&](int base, int expo) {
		int res = 1ll;
		while (expo) {
			if (expo & 1ll) res = (res * base) % mod;
			base = (base * base) % mod;
			expo >>= 1ll;
		}
		return res;
	};
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << fast_power(a, b) << '\n';
	}
	return 0;
}
