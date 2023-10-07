#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	const int mod = 998244353;
	int n, m, x, res = 1;
	queue<int> a_pf, b_pf, a_expo, b_expo;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a_pf.push(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		a_expo.push(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		b_pf.push(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		b_expo.push(x);
	}
	while (!a_pf.empty() && !b_pf.empty()) {
		if (a_pf.front() == b_pf.front()) {
			if (a_expo.front() < b_expo.front()) res = 0;
			else if (a_expo.front() > b_expo.front())
				res = res * 2 % mod;
			a_pf.pop();
			a_expo.pop();
			b_pf.pop();
			b_expo.pop();
		}
		else if (a_pf.front() < b_pf.front()) {
			res = res * 2 % mod;
			a_pf.pop();
			a_expo.pop();
		}
		else break;
	}
	if (!b_pf.empty()) res = 0;
	while (!a_pf.empty()) {
		res = res * 2 % mod;
		a_pf.pop();
		a_expo.pop();
	}
	cout << res << '\n';
	return 0;
}
