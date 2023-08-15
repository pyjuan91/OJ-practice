#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		c = c % 2;
		if (a + c > b) cout << "First\n";
		else cout << "Second\n";
	}
	return 0;
}
