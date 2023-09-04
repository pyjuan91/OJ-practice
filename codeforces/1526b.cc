#include <bits/stdc++.h>
#define int long long
using namespace std;
const int cadi[]
  = {11, 111, 1111, 11111, 111111, 1111111, 11111111};
bool chaewon(int x, int id) {
	if (id == 0) { return x % 11 == 0; }
	if (x % cadi[id] == 0) return true;
	for (int scalar = 1; scalar <= 1e7; scalar++) {
		if (x < scalar * cadi[id]) break;
		if (chaewon(x - scalar * cadi[id], id - 1)) return true;
	}
	return chaewon(x, id - 1);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		cout << (chaewon(x, 6) ? "YES" : "NO") << '\n';
	}
	return 0;
}
