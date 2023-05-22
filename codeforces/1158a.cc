#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, res = 0, x;
	cin >> n >> m;
	multiset<int> a, b;
	for (int i = 0; i < n; i++) cin >> x, a.insert(x);
	for (int i = 0; i < m; i++) cin >> x, b.insert(x);
	auto last_one = a.end();
	last_one--;
	if (*last_one > *b.begin()) {
		cout << "-1\n";
		return 0;
	}
	bool da = false;
	for (auto iter = b.begin(); iter != b.end(); iter++) {
		if (a.find(*iter) != a.end()) {
			da = true;
			res += *last_one;
		}
		else res += *iter;
	}
	if (da == false) {
		auto last_one_prev = last_one;
		last_one_prev--;
		res += *last_one - *last_one_prev;
	}
	for (auto iter = a.begin(); iter != last_one; iter++) {
		res += *iter * m;
	}
	cout << res;
	return 0;
}