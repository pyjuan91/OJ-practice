#include <bits/stdc++.h>
using namespace std;
int s[15] = {}, sel[15] = {};
int n, m, c, x;
int ans = 0;
void go(int cur) {
	if (cur == m) {
		int all = (1 << n) - 1;
		int jege = 0;
		for (int i = 0; i < m; i++)
			if (sel[i]) jege |= s[i];
		if (jege == all) ans += 1;
		return;
	}
	sel[cur] = 1;
	go(cur + 1);
	sel[cur] = 0;
	go(cur + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> c;
		for (int j = 0; j < c; j++) {
			cin >> x;
			x--;
			s[i] |= 1 << x;
		}
	}
	go(0);
	cout << ans << endl;
	return 0;
}