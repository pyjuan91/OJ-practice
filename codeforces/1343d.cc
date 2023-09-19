#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005], prefix[400010], cnt[400010];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i <= 2 * k; i++) cnt[i] = prefix[i] = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n / 2; i++) {
			cnt[a[i] + a[n - i - 1]]++;
			prefix[min(a[i], a[n - i - 1]) + 1]++;
			prefix[max(a[i], a[n - i - 1]) + k + 1]--;
		}
		int res = INT32_MAX;
		for (int i = 2; i <= 2 * k; i++) {
			prefix[i] += prefix[i - 1];
			int cost = prefix[i] - cnt[i] + (n / 2 - prefix[i]) * 2;
			res = min(res, cost);
		}
		cout << res << '\n';
	}
	return 0;
}
