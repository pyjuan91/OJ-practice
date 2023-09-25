#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m, s;
	cin >> m >> s;
	if (m == 1) {
		if (s >= 0 && s <= 9) cout << s << " " << s << "\n";
		else cout << "-1 -1\n";
		return 0;
	}
	string mi = "", ma = "";
	int mis = 1, mas = 9 * m;
	for (int i = 0; i < m; i++)
		mi.push_back('0'), ma.push_back('9');
	mi[0] = '1';
	// modify mi
	if (mis > s || mas < s) {
		cout << "-1 -1\n";
		return 0;
	}
	for (int i = m - 1; i >= 0; i--) {
		int diff = s - mis;
		if (diff >= 9) {
			mi[i] = '9';
			mis += 9;
		}
		else {
			mi[i] += diff;
			mis += diff;
		}
	}
	// modify ma
	for (int i = m - 1; i >= 0; i--) {
		int diff = mas - s;
		if (diff >= 9) {
			ma[i] = '0';
			mas -= 9;
		}
		else {
			ma[i] -= diff;
			mas -= diff;
		}
	}
	cout << mi << " " << ma << "\n";
	return 0;
}
