#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t, w, h, x1, x2, y1, y2, x, y, u, d, l, r;
	cin >> t;
	while (t--) {
		cin >> w >> h;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x >> y;
		l = x1;
		r = w - x2;
		u = h - y2;
		d = y1;
		if ((x > l + r) && (y > u + d))
			cout << "-1\n";
		else {
			int bigx = max(l, r);
			int bigy = max(u, d);
			if (!(x > l + r) && !(y > u + d))
				cout << max(0, min(x - bigx, y - bigy)) << "\n";
			else if (x > l + r)
				cout << max(0, y - bigy) << "\n";
			else cout << max(0, x - bigx) << "\n";
		}
	}
	return 0;
}