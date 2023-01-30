#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int ax1, ax2, ay1, ay2, bx1, bx2, by1, by2, ans;
	cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;
	ans = max(
		(max(ax2, bx2) - min(ax1, bx1)),
		(max(ay2, by2) - min(ay1, by1)));
	cout << ans * ans;
	return 0;
}