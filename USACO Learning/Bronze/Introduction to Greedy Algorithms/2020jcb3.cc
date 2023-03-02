#include <bits/stdc++.h>
using namespace std;
int chaewon(int k, int x) {
	if (k == 0) return 0;
	int cur = 0;
	int cs = 0;
	int res = 0;
	for (;;) {
		if (cur >= k) break;
		if (cs + 1 <= x) {
			cs += 1;
			cur += cs;
			res += 1;
		}
		else {
			if (cur + 2 * cs + 1 <= k) {
				cur += 2 * cs + 1;
				cs += 1;
				res += 2;
			}
			else {
				while (cur < k) {
					cur += cs;
					res += 1;
				}
			}
		}
	}
	return res;
}
int main() {
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int k, n, x;
	cin >> k >> n;
	while (n--) {
		cin >> x;
		cout << chaewon(k, x) << "\n";
	}
	return 0;
}