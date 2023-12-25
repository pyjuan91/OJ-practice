#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int n, string s) {
	int res = 0, vis[128] = {};
	for (int i = 0; i < n; i++) {
		if (!vis[s[i]]) {
			vis[s[i]] = 1;
			res += n - i;
		}
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		cout << chaewon(n, s) << '\n';
	}
	return 0;
}
