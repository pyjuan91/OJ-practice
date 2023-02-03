#include <bits/stdc++.h>
using namespace std;
int go(int a) {
	int res = 0;
	while (a) {
		res += a % 10;
		a /= 10;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t, n, q, cmd, x, l, r, id;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		vector<int> a(n);
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > 9) s.insert(i);
		}
		while (q--) {
			cin >> cmd;
			if (cmd == 1) {
				cin >> l >> r;
				l--, r--;
				id = l;
				while (!s.empty()) {
					auto iter = s.lower_bound(id);
					if (iter == s.end() || *iter > r) break;
					a[*iter] = go(a[*iter]);
					id = *iter + 1;
					if (a[*iter] < 10) s.erase(iter);
				}
			}
			else {
				cin >> x;
				cout << a[x - 1] << "\n";
			}
		}
	}
	return 0;
}