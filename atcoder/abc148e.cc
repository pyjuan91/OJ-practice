#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int n) {
	if (n % 2 || n < 10) return 0;
	int ans = 0, x = n / 2, base = 5;
	while (x >= base) {
		ans += x / base;
		if (base <= INT64_MAX / 5) base *= 5;
		else break;
	}
	return ans;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	cout << chaewon(n) << '\n';
	return 0;
}

