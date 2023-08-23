#include <bits/stdc++.h>
#define int long long
using namespace std;
int pos[200005];
int chaewon(int n, int a, int b) {
	int res = 0, capital = 0;
	for (int i = 1; i <= n; i++) {
		res += b * (pos[i] - capital);
		if ((n - i) * b > a) {
			res += a * (pos[i] - capital);
			capital = pos[i];
		}
	}
    return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		for (int i = 1; i <= n; i++) cin >> pos[i];
		cout << chaewon(n, a, b) << '\n';
	}
	return 0;
}
