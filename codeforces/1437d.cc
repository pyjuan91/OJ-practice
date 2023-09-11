#include <bits/stdc++.h>
using namespace std;
int a[200005], quota[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n + 5; i++) quota[i] = 0;
		quota[0] = 1;
		int res = 1, cp = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] < cp) quota[res - 1]--;
			if (quota[res - 1] == 0) res++;
			quota[res]++;
			cp = a[i];
		}
		cout << res << '\n';
	}
	return 0;
}
