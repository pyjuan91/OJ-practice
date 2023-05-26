#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(vector<int> &a, int h, int n, int i, int g, int b) {
	if (i == n) return 0;
	if (h > a[i])
		return 1 + chaewon(a, h + a[i] / 2, n, i + 1, g, b);
	auto eat_green = g > 0 ? chaewon(a, h * 2, n, i, g - 1, b) : 0;
	auto eat_blue = b > 0 ? chaewon(a, h * 3, n, i, g, b - 1) : 0;
	return max(eat_green, eat_blue);
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, h;
	cin >> t;
	while (t--) {
		cin >> n >> h;
		int res = 0, g = 2, b = 1;
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		sort(a.begin(), a.end());
		cout << chaewon(a, h, n, 0, 2, 1) << "\n";
	}
	return 0;
}