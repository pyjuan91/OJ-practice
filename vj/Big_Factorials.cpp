#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) res *= i, res %= 10000;
	cout << (res ? to_string(res) : "0000");
	return 0;
}
