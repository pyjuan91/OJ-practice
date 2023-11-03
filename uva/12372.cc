#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, c;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cout << "Case " << kase << ": ";
		cin >> a >> b >> c;
		if (a <= 20 && b <= 20 && c <= 20) cout << "good\n";
		else cout << "bad\n";
	}
	return 0;
}
