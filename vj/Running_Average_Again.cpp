#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	double x, su = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> x;
		su += x;
		cout << fixed << setprecision(10) << su / i << "\n";
	}
	return 0;
}
