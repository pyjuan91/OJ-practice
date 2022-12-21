#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> movies(n);
	for (int i = 0; i < n; i++) {
		cin >> movies[i].second >> movies[i].first;
	}
	sort(movies.begin(), movies.end());
	// for (auto i : movies) {
	// 	cout << i.first << " " << i.second << endl;
	// }
	multiset<int> endTime;
	int res = 0;
	for (int i = 0; i < k; i++)
		endTime.insert(0);
	// cout << endTime.size() << endl;
	for (int i = 0; i < n; i++) {
		// cout << movies[i].second << " " << movies[i].first << endl;
		auto it = endTime.upper_bound(movies[i].second);
		if (it == endTime.begin())continue;
		res += 1;
		endTime.erase(--it);
		endTime.insert(movies[i].first);
	}
	cout << res;
	return 0;
}