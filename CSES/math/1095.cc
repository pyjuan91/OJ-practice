#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int fast_power(int a, int b) {
	int res = 1;
	if (a == 0) {
		if (b == 0) return 1;
		return 0;
	}
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << fast_power(a, b) << "\n";
	}
	return 0;
}