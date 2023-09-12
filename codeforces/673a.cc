#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, diff_cnt = 0;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), c(n + 1), diff_connected(n + 1, 0);
	for (int i = 1; i < n; i++) cin >> a[i] >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++) {
		if (c[a[i]] != c[b[i]]) {
			diff_cnt++;
			diff_connected[a[i]]++;
			diff_connected[b[i]]++;
		}
	}
    for (int i = 1; i <= n; i++) {
        if (diff_connected[i] == diff_cnt) {
            cout << "YES\n" << i << '\n';
            return 0;
        }
    }
    cout << "NO\n";
	return 0;
}
