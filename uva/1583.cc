#include <bits/stdc++.h>
using namespace std;
map<int, int> ans;
int gen(int x) {
	int res = x;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
void chaewon() {
	for (int i = 1; i < 1000000; i++) {
		auto cur = gen(i);
		if (!ans.count(cur)) ans[cur] = i;
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	chaewon();
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (!ans.count(n)) cout << "0\n";
		else cout << ans[n] << '\n';
	}
	return 0;
}
