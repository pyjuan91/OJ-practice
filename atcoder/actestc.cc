#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if (x < 0) x += m;
	return x;
}

unsigned long long floor_sum_unsigned(
  unsigned long long n, unsigned long long m,
  unsigned long long a, unsigned long long b) {
	unsigned long long ans = 0;
	while (true) {
		if (a >= m) {
			ans += n * (n - 1) / 2 * (a / m);
			a %= m;
		}
		if (b >= m) {
			ans += n * (b / m);
			b %= m;
		}

		unsigned long long y_max = a * n + b;
		if (y_max < m) break;
		// y_max < m * (n + 1)
		// floor(y_max / m) <= n
		n = (unsigned long long) (y_max / m);
		b = (unsigned long long) (y_max % m);
		std::swap(m, a);
	}
	return ans;
}

long long floor_sum(long long n, long long m, long long a, long long b) {
	assert(0 <= n && n < (1LL << 32));
	assert(1 <= m && m < (1LL << 32));
	unsigned long long ans = 0;
	if (a < 0) {
		unsigned long long a2 = safe_mod(a, m);
		ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
		a = a2;
	}
	if (b < 0) {
		unsigned long long b2 = safe_mod(b, m);
		ans -= 1ULL * n * ((b2 - b) / m);
		b = b2;
	}
	return ans + floor_sum_unsigned(n, m, a, b);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m >> a >> b;
		cout << floor_sum(n, m, a, b) << "\n";
	}
	return 0;
}