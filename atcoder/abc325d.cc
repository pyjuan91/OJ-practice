#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, y, res = 0, cur_time = 0;
	cin >> n;
	vector<pair<int, int>> v(n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[i] = {x, x + y};
	}
	sort(v.rbegin(), v.rend());
	for (int ti = 0; 2e18; ti++) {
		if (v.empty() && pq.empty()) break;
		if (pq.empty() && !v.empty()) ti = v.back().first;
		while (!v.empty() && v.back().first == ti) {
			pq.push(v.back().second);
			v.pop_back();
		}
		while (!pq.empty() && pq.top() < ti) pq.pop();
		if (!pq.empty()) {
			pq.pop();
			res++;
		}
	}
	cout << res << '\n';
	return 0;
}
