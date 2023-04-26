#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += i - 1;
		}
		for (int i = 1; i <= n; i++) cin >> b[i];
		pair<int, int> p = {-1, 0};
		for (int i = 1; i <= n; i++)
			if (a[i] <= m && b[i] > p.first)
				p = make_pair(b[i], i);
		if (p.first == -1) cout << -1 << "\n";
		else cout << p.second << "\n";
	}
	return 0;
}