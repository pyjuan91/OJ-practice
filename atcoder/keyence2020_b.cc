#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, l, res = 0, ci = -1e15;
	vector<pair<int, int>> r;
	cin >> n;
	while (n--) {
		cin >> x >> l;
		r.emplace_back(make_pair(x - l + 1, x + l));
	}
	sort(r.rbegin(), r.rend(), [&](auto l, auto r) {
		if (l.second == r.second) return l.first < r.first;
		return l.second < r.second;
	});
	while (!r.empty()) {
		auto cr = r.back();
		r.pop_back();
		if (cr.first > ci) {
			ci = cr.second;
			res += 1;
		}
	}
	cout << res << "\n";
	return 0;
}