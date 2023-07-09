#include <bits/stdc++.h>
#define int long long
using namespace std;
int lcd(int a, int b) { return a / __gcd(a, b) * b; }
int chaewon(int n, vector<int>& a, vector<int>& b) {
	int res = 1, gc = 0, lc = 1;
	for (int i = 0; i < n; i++) {
		gc = __gcd(gc, a[i] * b[i]);
		lc = lcd(lc, b[i]);
		if (gc % lc) {
			res++;
			gc = a[i] * b[i];
			lc = b[i];
		}
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
		cout << chaewon(n, a, b) << "\n";
	}
	return 0;
}