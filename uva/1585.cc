#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int pre = 0, res = 0;
		for (auto c : s) {
			if (c == 'O') pre++;
			else pre = 0;
			res += pre;
		}
		cout << res << "\n";
	}
	return 0;
}
