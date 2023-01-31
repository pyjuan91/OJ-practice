#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int x[4], y[4];
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2]
		>> y[2] >> x[3] >> y[3];
	int diffX = max(0, min(x[1], x[3]) - max(x[0], x[2]));
	int diffY = max(0, min(y[1], y[3]) - max(y[0], y[2]));
	int dx = x[1] - x[0], dy = y[1] - y[0];
	if ((x[0] < x[2] && x[1] > x[3]) || (y[0] < y[2] && y[1] > y[3]))
		cout << dx * dy;
	else if ((x[0] < x[2] || x[1] > x[3]) && (y[0] < y[2] || y[1] > y[3]))
		cout << dx * dy;
	else cout << dx * dy - diffX * diffY;
	return 0;
}
