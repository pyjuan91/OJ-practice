#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (((x + y) / 2) % 2) cout << "Oops!\n";
		else cout << "Sadia will be happy.\n";
	}
	return 0;
}
