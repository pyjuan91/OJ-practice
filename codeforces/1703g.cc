#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][35], prefix[100005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i][0];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < 35; j++)
				a[i][j] = a[i][j - 1] / 2;
		}
		prefix[0] = 0;
		for (int i = 1; i <= n; i++)
			prefix[i] = prefix[i - 1] + a[i][0];
		auto dec_sum = [&](int start) {
			int sum = 0, deg = 1;
			for (int i = start; i <= min(n, start + 32ll); i++) {
				sum += a[i][deg];
				deg++;
			}
			return sum;
		};
		int res = INT64_MIN;
		for (int i = 0; i <= n; i++) {
			int sum = prefix[i] - k * i;
			if (i < n) sum += dec_sum(i + 1);
            res = max(res, sum);
		}
        cout << res << '\n';
	}
	return 0;
}