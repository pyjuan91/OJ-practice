#include <bits/stdc++.h>
using namespace std;
int ask(int x, int y) {
	cout << "? " << x << " " << y << "\n";
	cout.flush();
	int d;
	cin >> d;
	return d;
}
void answer(int x, int y) {
	cout << "! " << x << " " << y << "\n";
	cout.flush();
}
int32_t main() {
	int t, n, m, d, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		d = ask(1, 1);
		if (d == 0) {
			answer(1, 1);
			continue;
		}
		if (1 + d <= min(n, m)) {
			x = y = 1 + d;
			d = ask(x, y);
			if (d == 0) {
				answer(x, y);
				continue;
			}
			x -= d;
			d = ask(x, y);
			if (d == 0) answer(x, y);
			else answer(x + d, y - d);
		}
		else {
			if (1 + d > n) {
				x = 1, y = 1 + d;
				d = ask(x, y);
				answer(x + d, y);
			}
			else {
				x = 1 + d, y = 1;
				d = ask(x, y);
				answer(x, y + d);
			}
		}
	}
	return 0;
}