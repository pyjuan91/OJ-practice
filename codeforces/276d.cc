#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, l, r;
	cin >> l >> r;
	a = r, b = l;
	for (int i = 61; i >= 0; i--) {
		bool popa = a & (1LL << i);
		bool popb = b & (1LL << i);
		if (popa ^ popb) continue;
		else if (popa) {
			int tmpa = a - (1LL << i);
			int tmpb = b - (1LL << i);
			if (tmpa >= l) a = tmpa;
			else if (tmpb >= l) b = tmpb;
		}
		else {
			int tmpa = a + (1LL << i);
			int tmpb = b + (1LL << i);
			if (tmpa <= r) a = tmpa;
			else if (tmpb <= r) b = tmpb;
		}
	}
	cout << (a ^ b) << '\n';
	return 0;
}
