#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> primes;
vector<int> LPFs(1e7 + 1, 1);
map<int, int> primes_power;
void init() {
	for (int i = 2; i < 1e7; ++i) {
		if (LPFs[i] == 1) {
			LPFs[i] = i;
			primes.emplace_back(i);
		}
		for (auto p : primes) {
			if (1LL * i * p > 1e7) break;
			LPFs[i * p] = p;
			if (i % p == 0) break;
		}
	}
}
void prime_factor(int x) {
	while (x != 1) {
		int factor = LPFs[x], cnt = 0;
		for (; x % factor == 0; ++cnt) x /= factor;
		primes_power[factor] += cnt;
	}
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, a, odd_remain, res;
	init();
	cin >> t;
	while (t--) {
		odd_remain = res = 0;
		primes_power.clear();
		cin >> n;
		while (n--) {
			cin >> a;
			prime_factor(a);
		}
		for (auto i : primes_power) {
			res += i.second / 2;
			odd_remain += i.second % 2;
		}
		cout << 1LL * res + odd_remain / 3 << "\n";
	}
	return 0;
}