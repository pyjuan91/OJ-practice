#include <bits/stdc++.h>
using namespace std;
int a[300005];
set<int> lose, win;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		lose.clear(), win.clear();
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		lose.insert(a[0]);
		for (int i = 1; i < n; i++) {
			auto it = lose.lower_bound(a[i]);
			if (it == lose.begin()) lose.insert(a[i]);
			else {
				if (win.empty()) win.insert(a[i]);
				else {
					it = win.lower_bound(a[i]);
					if (it == win.begin()) win.insert(a[i]);
					else lose.insert(a[i]);
				}
			}
		}
        cout << win.size() << '\n';
	}
	return 0;
}
