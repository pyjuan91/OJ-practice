#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	auto is_prime = [&](int x) {
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) return false;
		}
		return true;
	};
	if (is_prime(n)) {
		cout << 1 << '\n' << n << '\n';
		return 0;
	}
	if (is_prime(n - 2)) {
		cout << 2 << '\n' << 2 << ' ' << n - 2 << '\n';
		return 0;
	}
	for (int i = 3; i <= n - 3; i += 2) {
		if (is_prime(i) && is_prime(n - 3 - i)) {
			cout << 3 << '\n'
				 << 3 << ' ' << i << ' ' << n - 3 - i << '\n';
			return 0;
		}
	}
	return 0;
}
