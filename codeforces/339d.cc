#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	n = 1 << n;
	vector<pair<int, bool>> a(2 * n);
	for (int i = 0; i < n; i++)
		cin >> a[i + n].first, a[i + n].second = true;
	auto build_tree = [&]() {
		for (int i = n - 1; i > 0; i--) {
			auto child1 = a[i << 1], child2 = a[i << 1 | 1];
			if (child1.second)
				a[i] = {child1.first | child2.first, false};
			else a[i] = {child1.first ^ child2.first, true};
		}
	};
	build_tree();
	auto update = [&](int id, int val) {
		id = n + id - 1;
		a[id].first = val;
		while (id > 0) {
			id >>= 1;
			auto child1 = a[id << 1], child2 = a[id << 1 | 1];
			if (child1.second)
				a[id] = {child1.first | child2.first, false};
			else a[id] = {child1.first ^ child2.first, true};
		}
	};
    while (m--) {
        int id, val;
        cin >> id >> val;
        update(id, val);
        cout << a[1].first << '\n';
    }
	return 0;
}
