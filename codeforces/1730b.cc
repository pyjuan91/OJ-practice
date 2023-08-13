#include <bits/stdc++.h>
using namespace std;
int a[100005], t[100005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tt, n;
	cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> t[i];
		int max_co = INT32_MIN, min_co = INT32_MAX;
		for (int i = 0; i < n; i++) {
			max_co = max(max_co, a[i] + t[i]);
			min_co = min(min_co, a[i] - t[i]);
		}
		int su = max_co + min_co;
		cout << su / 2;
		if (su % 2) cout << ".5";
        cout << '\n';
	}
	return 0;
}
