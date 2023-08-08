#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x, even, odd;
	cin >> t;
	while (t--) {
		cin >> n;
		even = odd = 0;
		while (n--) {
			cin >> x;
			if (x % 2) odd++;
			else even++;
		}
		if (odd % 2) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
