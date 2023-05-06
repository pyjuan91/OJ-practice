#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (n == m) cout << "YES\n";
		else if (n % 3 != 0) cout << "NO\n";
		else if (m > n / 3 * 2) cout << "NO\n";
		else {
			queue<int> q;
			q.push(n);
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				if (cur == m) {
					cout << "YES\n";
					goto chaewon;
				}
				if (cur % 3 == 0 && cur > m) {
					q.push(cur / 3);
					q.push(cur / 3 * 2);
				}
			}
			cout << "NO\n";
		}
	chaewon: {}
	}
	return 0;
}