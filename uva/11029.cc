#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, left, right;
	cin >> t;
	auto get_right = [](int a, int b) {
		int res = 1ll;
		while (b) {
			if (b & 1ll) res = res * a % 1000ll;
			a = a * a % 1000ll;
			b >>= 1ll;
		}
		return res;
	};
	auto get_left = [](int a, int b) {
		double lnb = (double) b * log10((double) a);
		int x = (int) lnb;
		double y = lnb - x;
		return (int) (pow(10.0, y) * 100.0);
	};
	while (t--) {
		cin >> a >> b;
		right = get_right(a, b);
		left = get_left(a, b);
		printf("%lld...%03lld\n", left, right);
	}
	return 0;
}
