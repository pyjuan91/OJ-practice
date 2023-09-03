#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int h, m;
	double hangle, mangle;
	cin >> h >> m;
	hangle = 30.0 * h + 1.0 * m / 2;
	mangle = m * 6.0;
	cout << min(abs(hangle - mangle), 360 - abs(hangle - mangle)) << '\n';
	return 0;
}
