#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, op, x;
	map<int, int> factors;
	auto multiply = [&](int x) {
		for (int i = 2; i * i <= x; i++) {
			while (x % i == 0) {
				factors[i]++;
				x /= i;
			}
		}
		if (x > 1) factors[x]++;
	};
	auto check_has_a_sol = [&]() {
		int factors_cnt = 1;
		for (auto p : factors) factors_cnt *= p.second + 1;
		for (int i = 2; i * i <= factors_cnt; i++) {
			int current = 0;
			if (factors_cnt % i == 0) {
				while (factors_cnt % i == 0) {
					factors_cnt /= i;
					current++;
				}
				if (!factors.count(i) || factors[i] < current)
					return false;
			}
		}
		if (factors_cnt > 1 && !factors.count(factors_cnt))
			return false;
		return true;
	};
	cin >> t;
	while (t--) {
		cin >> n >> m;
		factors.clear();
		multiply(n);
		while (m--) {
			cin >> op;
			if (op == 1) {
				cin >> x;
				multiply(x);
				cout << (check_has_a_sol() ? "YES\n" : "NO\n");
			}
			else {
				factors.clear();
				multiply(n);
			}
		}
		cout << "\n";
	}
	return 0;
}