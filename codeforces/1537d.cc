#include <bits/stdc++.h>
#define int long long
using namespace std;
bool is_prime(int x) {
	if (x == 1) return true;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}
bool chaewon(int x) {
	if (x % 2 == 1) return false;
	if (x == 2) return false;
	int y = x;
	while (y % 2 == 0) y /= 2;
	if (y == 1) return (int)log2(x) % 2 == 0;
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (chaewon(n) ? "Alice" : "Bob") << '\n';
	}
	return 0;
}
