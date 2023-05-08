#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int fast_power(int base, int power) {
	int res = 1;
	while (power) {
		if (power & 1) res = (res * base) % mod;
		base = (base * base) % mod;
		power >>= 1;
	}
	return res;
}
const int two_inv = fast_power(2, mod-2);
int chaewon(int left, int right) {
	int whole
	  = ((((right % mod) * ((right + 1) % mod)) % mod) * two_inv) % mod;
	int half_left
	  = (((((left - 1) % mod) * (left % mod)) % mod) * two_inv) % mod;
	if (half_left > whole) whole += mod;
	return (whole - half_left) % mod;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	int div = 1;
	while (div <= n) {
		int mul = n / div;
		int last_greatest_same = n / mul;
		res = (res + ((mul % mod) * chaewon(div, last_greatest_same)) % mod)
			% mod;
		div = last_greatest_same + 1;
	}
	cout << res;
	return 0;
}