#include <bits/stdc++.h>
using namespace std;
double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int x1, y1, x2, y2, t, v, n, x3, y3;
	bool possible = false;
	cin >> x1 >> y1 >> x2 >> y2 >> t >> v >> n;
	while (n--) {
		cin >> x3 >> y3;
		if (distance(x1, y1, x3, y3) + distance(x3, y3, x2, y2) <= t * v)
			possible = true;
	}
	if (possible) cout << "YES";
	else cout << "NO";
	return 0;
}