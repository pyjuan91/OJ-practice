#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> a >> b;
		cout << "Case " << kase << ": " << a * a + b * b << '\n';
	}
	return 0;
}
