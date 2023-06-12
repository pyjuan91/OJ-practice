#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
void chaewon(int l, int r) {
	int first = (int) log2(r / l) + 1, rhs = 1 << (first - 1),
		second = r / rhs - l + 1;
	cout << first << " ";
	if (rhs > 1) {
		rhs /= 2, rhs *= 3;
		if (l * rhs <= r)
			second += (r / rhs - l + 1) * (first - 1);
	}
	cout << second % mod << "\n";
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, l, r;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		chaewon(l, r);
	}
	return 0;
}