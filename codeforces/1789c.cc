#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 4e5 + 5;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, res = 0, p, v;
		cin >> n >> m;
		vector<int> cnt(n + m + 1, 0),
		  occur_round(n + m + 1, -1), a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			occur_round[a[i]] = 0;
		}
		for (int i = 1; i <= m; i++) {
			cin >> p >> v;
			cnt[a[p]] += i - occur_round[a[p]];
			occur_round[a[p]] = -1;
			a[p] = v;
			occur_round[v] = i;
		}
		for (int i = 1; i <= n; i++)
			if (occur_round[a[i]] != -1)
				cnt[a[i]] += (m + 1) - occur_round[a[i]];

		for (int i = 1; i <= n + m; i++)
			res += (m + 1) * m / 2 - (m - cnt[i]) * (m - cnt[i] + 1) / 2;

		cout << res << "\n";
	}
}