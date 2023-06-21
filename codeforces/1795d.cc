#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int fast_power(int base, int power) {
	int res = 1;
	while (power) {
		if (power & 1) res = res * base % MOD;
		base = base * base % MOD;
		power >>= 1;
	}
	return res;
}
int find_inverse(int x) { return fast_power(x, MOD - 2); }
int factorial(int x) {
	static vector<int> f = {1};
	while (f.size() <= x)
		f.push_back(f.back() * f.size() % MOD);
	return f[x];
}
int combination(int up, int down) {
	return factorial(up) * find_inverse(factorial(down)) % MOD
		 * find_inverse(factorial(up - down)) % MOD;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 1;
	cin >> n;
	for (int i = 0; i < n; i += 3) {
		int edge[3];
		cin >> edge[0] >> edge[1] >> edge[2];
		sort(edge, edge + 3);
		if (edge[0] == edge[1] && edge[1] == edge[2])
			res = res * 3 % MOD;
		else if (edge[0] == edge[1]) res = res * 2 % MOD;
	}
	auto fp = combination(n / 3, n / 6);
	res = res * fp % MOD;
	cout << res;
	return 0;
}