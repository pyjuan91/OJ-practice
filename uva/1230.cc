#include <bits/stdc++.h>
#define int long long
using namespace std;
int fast_power(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, mod;
	while (cin >> t && t) {
		while (t--) {
			cin >> a >> b >> mod;
			cout << fast_power(a, b, mod) << '\n';
		}
	}
	return 0;
}
