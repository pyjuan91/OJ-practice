#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	ifstream cin("mountains.in");
	ofstream cout("mountains.out");
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, y;
	cin >> n;
	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		a.emplace_back(x - y, x + y);
	}
	sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	});
	int res = 0, cur_right = INT32_MIN;
	for (const auto& [l, r] : a) {
		if (r <= cur_right) continue;
		res++;
		cur_right = r;
	}
    cout << res << '\n';
	return 0;
}
