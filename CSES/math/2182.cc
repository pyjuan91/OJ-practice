#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using namespace std;
int fast_power(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int sum_of_geo_series(int base, int max_expo) {
	// (base ^ (max_expo + 1) - 1) / (base - 1)
	int dominator = (fast_power(base, max_expo + 1, MOD) - 1 + MOD) % MOD;
	int numerator = fast_power(base - 1, MOD - 2, MOD);
	return dominator * numerator % MOD;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, num_of_div = 1, sum_of_div = 1, mul_of_div = 1;
	bool all_expo_even = true;
	cin >> n;
	vector<int> x(n), k(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> k[i];
		if (k[i] % 2) all_expo_even = false;
		num_of_div = num_of_div * (k[i] + 1) % MOD;
	}

	for (int i = 0; i < n; i++) {
		sum_of_div = sum_of_div * sum_of_geo_series(x[i], k[i]) % MOD;
	}

	if (!all_expo_even) {
		int expo = 1;
		bool wait_div_two = true;
		for (int i = 0; i < n; i++) {
			if (wait_div_two && k[i] % 2) {
				expo = expo * (k[i] + 1) / 2 % (MOD - 1);
				wait_div_two = false;
			}
			else { expo = expo * (k[i] + 1) % (MOD - 1); }
		}
		for (int i = 0; i < n; i++) {
			mul_of_div
			  = mul_of_div
			  * fast_power(x[i], expo * k[i] % (MOD - 1), MOD) % MOD;
		}
	}
	else {
		int expo = 1;
		for (int i = 0; i < n; i++) {
			expo = expo * (k[i] + 1) % (MOD - 1);
		}
		for (int i = 0; i < n; i++) {
			mul_of_div
			  = mul_of_div
			  * fast_power(x[i], k[i] / 2 * expo % (MOD - 1), MOD) % MOD;
		}
	}
    cout << num_of_div << " " << sum_of_div << " " << mul_of_div;
	return 0;
}