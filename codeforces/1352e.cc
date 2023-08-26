#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[8005], prefix[8005], l, r, res;
	cin >> t;
	while (t--) {
		prefix[0] = res = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			prefix[i] = a[i] + prefix[i - 1];
		}
		if (n < 3) {
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			l = 0;
			r = 2;
			while (r <= n) {
				if (prefix[r] - prefix[l] == a[i]) {
					res++;
					break;
				}
				else if (prefix[r] - prefix[l] < a[i]) r++;
				else {
					l++;
					if (l + 1 >= r) r++;
				}
			}
		}
        cout << res << '\n';
	}
	return 0;
}
