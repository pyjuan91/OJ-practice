#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> m >> s;
		int b_cnt = 0;
		for (auto c : s) b_cnt += (c == 'B');
		if (b_cnt == m) cout << "0\n";
		else if (b_cnt > m) {
			if (m == 0) {
				cout << "1\n";
				cout << n << " A\n";
				continue;
			}
			cout << "1\n";
			b_cnt = 0;
			for (int i = n - 1; i >= 0; i--) {
				b_cnt += (s[i] == 'B');
				if (b_cnt == m) {
					cout << i << " A\n";
					break;
				}
			}
		}
		else {
			cout << "1\n";
			int a_cnt = 0;
			for (int i = 0; i < n; i++) {
				a_cnt += (s[i] == 'A');
				if (a_cnt == m - b_cnt) {
					cout << i + 1 << " B\n";
					break;
				}
			}
		}
	}
	return 0;
}
