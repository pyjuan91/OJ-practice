#include <bits/stdc++.h>
using namespace std;
const int ma = 1e6 + 5;
int num[ma];
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		num[x] += 1;
	}
	for (int res = ma; res > 0; res--) {
		int cnt = 0;
		for (int gcd = res; gcd < ma; gcd += res)
			cnt += num[gcd];
		if (cnt > 1) {
			cout << res;
			break;
		}
	}
	return 0;
}