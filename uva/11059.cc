#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a[20], kase = 1;
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int cond = 0; cond < (1 << n); cond++) {
			int prod = 1;
			bool consi = false;
			for (int i = 0; i < n; i++) {
				if (cond & (1 << i)) prod *= a[i], consi = true;
				else {
					if (consi) ans = max(ans, prod);
					prod = 1;
					consi = false;
				}
			}
            if (consi) ans = max(ans, prod);
		}
		cout << "Case #" << kase++
			 << ": The maximum product is " << ans << ".\n\n";
	}
	return 0;
}
