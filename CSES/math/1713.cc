#include <bits/stdc++.h>
using namespace std;
int chaewon(int x) {
	if (x == 1) return 1;
	int res = 1, sq = sqrt(x);
	for (int i = 2; i <= sq; i++) {
		int current = 1;
		while (x % i == 0) {
			x /= i;
			current += 1;
		}
		res *= current;
	}
	if (x > 1) return res * 2;
	return res;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		cout << chaewon(x) << "\n";
	}
	return 0;
}