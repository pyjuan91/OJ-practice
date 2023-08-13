#include <bits/stdc++.h>
#define int long long
using namespace std;
int rec[1001][1001], prefix[1001][1001];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, w, h, w2, h2;
	cin >> t;
	while (t--) {
		memset(rec, 0, sizeof(rec));
		memset(prefix, 0, sizeof(prefix));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> w >> h;
			rec[w][h]++;
		}
		for (int i = 1; i <= 1000; i++) {
			for (int j = 1; j <= 1000; j++) {
				prefix[i][j]
				  = (prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + rec[i][j] * i * j);
			}
		}
		for (int i = 0; i < m; i++) {
			cin >> w >> h >> w2 >> h2;
			cout << prefix[w2 - 1][h2 - 1] - prefix[w][h2 - 1]
					  - prefix[w2 - 1][h] + prefix[w][h]
				 << '\n';
		}
	}
	return 0;
}
