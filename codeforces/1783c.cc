#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> a(n), sorted_a;
		for (auto& x : a) cin >> x, sorted_a.emplace_back(x);
		sort(sorted_a.begin(), sorted_a.end());
		int ss = 0, place = 0;
		for (int i = 0; i < n; i++) {
			if (ss + sorted_a[i] <= m) {
				place++;
				ss += sorted_a[i];
			}
			else break;
		}
		if (place > 0 && place < n && ss - sorted_a[place - 1] + a[place] <= m)
			place++;
		cout << n - place + 1 << "\n";
	}
	return 0;
}