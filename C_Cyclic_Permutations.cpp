#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	const int mod = 1e9 + 7;
	cin >> n;
	auto factorial = [&](int x) {
		int res = 1;
		for (int i = 2; i <= x; i++) {
			res *= i;
			res %= mod;
		}
		return res;
	};
	auto fast_power = [&](int base, int pow) {
		int res = 1;
		while (pow) {
			if (pow & 1) {
				res *= base;
				res %= mod;
			}
			base *= base;
			base %= mod;
			pow >>= 1;
		}
		return res;
	};
	cout << (factorial(n) + mod - fast_power(2, n - 1)) % mod << '\n';
	return 0;
}
