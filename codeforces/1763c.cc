#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a, b, c;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			cin >> a >> b;
			cout << max(a + b, 2 * llabs(a - b)) << '\n';
		}
		else if (n == 3) {
			cin >> a >> b >> c;
			cout << max(
			  {a + b + c, 3 * a, 3 * c, 3 * (llabs(a - b)),
			   3 * llabs(b - c)})
				 << '\n';
		}
		else {
			b = INT32_MIN;
			for (int i = 0; i < n; i++) cin >> a, b = max(b, a);
			cout << n * b << '\n';
		}
	}
	return 0;
}
