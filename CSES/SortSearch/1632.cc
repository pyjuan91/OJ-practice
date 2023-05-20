#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, k, res = 0;
	cin >> n >> k;
	vector<pair<int, int>> movies(n);
	for (auto &p : movies) cin >> p.second >> p.first;
	sort(movies.begin(), movies.end());
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		if (!s.empty()) {
			auto iter = s.upper_bound(movies[i].second);
			if (iter != s.begin()) {
				iter--;
				res += 1;
				s.erase(iter);
				s.insert(movies[i].first);
			}
			else if (k) {
				k -= 1;
				res += 1;
				s.insert(movies[i].first);
			}
		}
		else if (k) {
			k -= 1;
			res += 1;
			s.insert(movies[i].first);
		}
	}
	cout << res;
	return 0;
}