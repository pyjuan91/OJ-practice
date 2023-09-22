#include <bits/stdc++.h>
#define int long long
using namespace std;
const int ma = 2e5 + 5;
int t, w, s, n, m, res[ma] = {};
auto cmp
  = [](pair<long long, long long> a, pair<long long, long long> b) {
	// Compare based on the first element of the pair
	return a.first > b.first;
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
priority_queue<int, vector<int>, greater<int>> q;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) q.push(i);
	while (m--) {
		cin >> t >> w >> s;
		while (!pq.empty() && pq.top().first <= t) {
			q.push(pq.top().second);
			pq.pop();
		}
		if (!q.empty()) {
            res[q.top()] += w;
			pq.push({t + s, q.top()});
			q.pop();
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << "\n";
	return 0;
}
