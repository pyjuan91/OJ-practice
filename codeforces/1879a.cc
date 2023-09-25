#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, s[105], e[105];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i] >> e[i];
		auto chaewon = [&]() {
			for (int i = 1; i < n; i++) {
				if (s[i] >= s[0] && e[i] >= e[0]) return false;
			}
			return true;
		};
		if (chaewon()) cout << s[0] << '\n';
		else cout << "-1\n";
	}
	return 0;
}
