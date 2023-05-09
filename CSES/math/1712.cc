#include <bits/stdc++.h>
#define int long long
using namespace std;
int fast_power(int a, int b, int mod) {
	int res = 1;
	if (a == 0) {
		if (b == 0) return 1;
		return 0;
	}
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int chaewon(int a, int b, int c) {
	auto p = fast_power(b, c, 1e9 + 7 - 1);
	return fast_power(a, p, 1e9 + 7);
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		cout << chaewon(a, b, c) << "\n";
	}
	return 0;
}