#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a < b) cout << "<\n";
		else if (a > b) cout << ">\n";
		else cout << "=\n";
	}
	return 0;
}
