#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a.begin(), a.end());
		vector<int> prefix_sum(n + 1, 0), res(n);
		for (int i = 0; i < n; i++)
			prefix_sum[i + 1] = prefix_sum[i] + a[i].first;
		for (int i = 0; i < n; i++) {
			res[a[i].second] = n + (prefix_sum[n] - prefix_sum[i + 1])
							 - (n - i - 1) * a[i].first
							 + i * a[i].first - prefix_sum[i];
		}
        for (auto& x : res) cout << x << ' ';
        cout << '\n';
	}
	return 0;
}
