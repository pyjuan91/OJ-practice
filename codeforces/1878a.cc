#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k, x;
	cin >> t;
	while (t--) {
		bool appear = false;
		cin >> n >> k;
		while (n--) {
			cin >> x;
			if (x == k) appear = true;
		}
        cout << (appear ? "YES\n" : "NO\n");
	}

	return 0;
}
