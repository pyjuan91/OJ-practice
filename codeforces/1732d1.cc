#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q, x, scalar;
	set<int> s;
	map<int, int> m;
	char op;
	cin >> q;
	while (q--) {
		cin >> op >> x;
		if (op == '+') {
			s.insert(x);
			m[x] = 2;
		}
		else {
			if (!m.count(x)) scalar = 1;
			else scalar = m[x];
			while (s.find(x * scalar) != s.end()) scalar++;
			m[x] = scalar;
			cout << x * scalar << '\n';
		}
	}
	return 0;
}
