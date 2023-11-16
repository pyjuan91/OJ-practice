#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;
int a[maxn];
priority_queue<int, vector<int>, greater<int>> R;
priority_queue<int> L;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, sz, ideal_left, x;
	cin >> t;
	for (int kase = 0; kase < t; kase++) {
		if (kase) cout << '\n';
		cin >> n >> m;
		sz = ideal_left = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) {
			cin >> x;
			for (int j = sz; j < x; j++) {
				if (R.empty() || R.top() <= a[j]) R.push(a[j]);
				else L.push(a[j]);
			}
			sz = x;
			while (L.size() < ideal_left)
				L.push(R.top()), R.pop();
			while (L.size() > ideal_left)
				R.push(L.top()), L.pop();
			cout << R.top() << '\n';
			ideal_left++;
		}
		while (!R.empty()) R.pop();
		while (!L.empty()) L.pop();
	}
	return 0;
}
