#include <bits/stdc++.h>
using namespace std;
void chaewon(
  int cur, int& cc_sum, set<int>& not_used,
  vector<unordered_set<int>>& route, int n) {
	cc_sum += 1;
	auto iter = not_used.begin();
	while (iter != not_used.end()) {
		if (route[cur].count(*iter)) iter++;
		else {
			auto child = *iter;
			not_used.erase(iter);
			chaewon(child, cc_sum, not_used, route, n);
			iter = not_used.lower_bound(child);
		}
	}
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	vector<unordered_set<int>> route(n + 1);
	while (m--) {
		cin >> a >> b;
		route[a].insert(b);
		route[b].insert(a);
	}
	set<int> not_used;
	vector<int> res;
	for (int i = 1; i <= n; i++) not_used.insert(i);
	for (int i = 1; i <= n; i++) {
		auto iter = not_used.find(i);
		if (iter != not_used.end()) {
			not_used.erase(iter);
			int cc_sum = 0;
			chaewon(i, cc_sum, not_used, route, n);
			res.emplace_back(cc_sum);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (auto& x : res) cout << x << " ";
	cout << "\n";
	return 0;
}