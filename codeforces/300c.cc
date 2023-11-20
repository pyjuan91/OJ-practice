#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int factorial[1000001];
int fast_power(int base, int expo) {
	int ans = 1;
	while (expo) {
		if (expo & 1) { ans = (ans * base) % mod; }
		base = (base * base) % mod;
		expo >>= 1;
	}
	return ans;
}
int combination(int a, int b) {
	int denominator = (factorial[b] * factorial[a - b]) % mod;
	return (factorial[a] * fast_power(denominator, mod - 2)) % mod;
}
bool good(int x, int a, int b) {
	while (x) {
		int digit = x % 10;
		if (digit != a && digit != b) { return false; }
		x /= 10;
	}
	return true;
}
int chaewon(int a, int b, int n) {
	int res = 0;
	for (int a_cnt = 0; a_cnt <= n; a_cnt++) {
		int b_cnt = n - a_cnt;
		int sum = a_cnt * a + b_cnt * b;
		if (good(sum, a, b))
			res = (res + combination(n, a_cnt)) % mod;
	}
    return res;
}
int32_t main() {
	factorial[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		factorial[i] = (factorial[i - 1] * i) % mod;
	}

	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, n;
	cin >> a >> b >> n;
	cout << chaewon(a, b, n);
	return 0;
}
