#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x;
	cin >> x;
	string res = "";
	while (x != 0) {
		if (x % -2 == 0) res.push_back('0'), x /= -2;
		else res.push_back('1'), x = (x - 1) / -2;
	}
	reverse(res.begin(), res.end());
	cout << (res == "" ? "0" : res);
	return 0;
}
