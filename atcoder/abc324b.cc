#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x;
	cin >> x;
	auto check = [&](int x) {
		while (x % 2 == 0) x /= 2;
		while (x % 3 == 0) x /= 3;
		return x == 1;
	};
	cout << (check(x) ? "Yes" : "No");
	return 0;
}
