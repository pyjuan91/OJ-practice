#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	for (int y = 0; y < w; y++) {
		if (y * d > p) break;
		if ((p - y * d) % w != 0) continue;
		int x = (p - y * d) / w;
		if (x + y <= n) {
			cout << x << " " << y << " " << n - x - y << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
