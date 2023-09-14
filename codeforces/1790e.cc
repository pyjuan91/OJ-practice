#include <bits/stdc++.h>
using namespace std;
#define int long long
int sol1, sol2;
bool chaewon(int n, int a, int b, int i) {
	if ((a + b) % 2 == 0 && (a + b) / 2 == n) {
		sol1 = a;
		sol2 = b;
		return true;
	}
	if (i >= 32) return false;
	if ((a + b) / 2 > n) return false;
	int c = (a + b) / 2;
	for (int j = 0; j < i-1; j++) {
		if ((c & (1LL << j)) != (n & (1LL << j))) return false;
	}
	if (n & (1LL << i)) {
		a |= (1LL << i);
		if (chaewon(n, a, b, i + 1)) return true;
		a ^= (1LL << i);
		b |= (1LL << i);
		if (chaewon(n, a, b, i + 1)) return true;
		return false;
	}
	if (chaewon(n, a, b, i + 1)) return true;
	a |= (1LL << i);
	b |= (1LL << i);
	if (chaewon(n, a, b, i + 1)) return true;
	return false;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	// auto check = [](int a, int b, int n) {
	// 	if ((a + b) % 2 == 0 && (a + b) / 2 == n) {
	// 		if (a ^ b == n) return true;
	// 		return false;
	// 	}
	// 	return false;
	// };
	while (t--) {
		cin >> n;
		if (chaewon(n, 0, 0, 0)) {
			cout << sol1 << ' ' << sol2 << '\n';
			// cout << (check(sol1, sol2, n) ? "YES" : "NO") << '\n';
		}
		else cout << -1 << '\n';
	}
	return 0;
}
