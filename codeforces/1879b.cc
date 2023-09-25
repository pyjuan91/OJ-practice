#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int t, n, a[maxn], b[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		int sua = 0, sub = 0;
		for (int i = 0; i < n; i++) cin >> a[i], sua += a[i];
		for (int i = 0; i < n; i++) cin >> b[i], sub += b[i];
		int mia = *min_element(a, a + n), mib = *min_element(b, b + n);
		cout << min(sua + n * mib, sub + n * mia) << '\n';
	}
	return 0;
}
