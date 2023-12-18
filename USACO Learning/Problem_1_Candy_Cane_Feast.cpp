#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 0), b(m + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];

	deque<pair<int, int>> dq;
	dq.push_back(make_pair(a[1], 1));
	for (int i = 2; i <= n; i++) {
		if (a[i] <= dq.back().first) continue;
		dq.push_back(make_pair(a[i], i));
	}

	for (int i = 1; i <= m; i++) {
		vector<pair<int, int>> update;
		int ground = 0;
		while (!dq.empty() && ground < b[i]) {
			pair<int, int> cur = dq.front();
			dq.pop_front();
			int eat = min(b[i], cur.first) - ground;
			ground += eat;
			update.push_back(make_pair(cur.first + eat, cur.second));
		}
		// for (auto x : update)
		// 	cout << x.first << " " << x.second << "\n";
		// cout << "\n";
		while (!update.empty()) {
			while (!dq.empty()
				   && dq.front().first <= update.back().first) {
				a[dq.front().second] = dq.front().first;
				dq.pop_front();
			}
			dq.push_front(update.back());
			update.pop_back();
		}
	}
	while (!dq.empty()) {
		a[dq.front().second] = dq.front().first;
		dq.pop_front();
	}
	for (int i = 1; i <= n; i++) cout << a[i] << "\n";
	return 0;
}
