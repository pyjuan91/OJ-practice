#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int l = n, r = INT64_MAX;
		bool ok = true;
		for (int i = 0; i < 64; i++) {
			bool cn = (1LL << i) & n;
			bool cx = (1LL << i) & x;
			if (!cn && !cx) continue;
			if (cn && cx)
				r = min(
				  r, ((n >> (i + 1)) << (i + 1)) + ((1LL << (i + 1)) - 1));
			if (!cn && cx) ok = false;
			if (cn && !cx)
				l = max(l, ((n >> (i + 1)) << (i + 1)) + (1LL << (i + 1)));
		}
		if (l > r || !ok) cout << "-1\n";
		else cout << l << "\n";
	}
	return 0;
}