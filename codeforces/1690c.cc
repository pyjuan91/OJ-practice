#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	const int N = 1000000;
	vector<int> lp(N + 1);
	vector<int> pr;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) { break; }
		}
	}
	auto is_prime = [&](int x) { return lp[x] == x; };

	int t, n, e;
	cin >> t;
	while (t--) {
		cin >> n >> e;
		int res = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			if (is_prime(a[i])) {
				int left = 0, right = 0;
				for (int j = i + e; j < n; j += e) {
					if (a[j] == 1) right++;
					else break;
				}
				for (int j = i - e; j >= 0; j -= e) {
					if (a[j] == 1) left++;
					else break;
				}
				res += left * right + left + right;
			}
		}
        cout << res << '\n';
	}
	return 0;
}
