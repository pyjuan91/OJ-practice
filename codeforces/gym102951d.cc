#include <bits/stdc++.h>
#define int long long
using namespace std;
int find_index(vector<int>& a, int& target) {
	auto iter = lower_bound(begin(a), end(a), target);
	return iter - begin(a);
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, q, l, r, v;
	cin >> n >> q;
	vector<int> indices;
	vector<pair<pair<int, int>, int>> update;
	vector<pair<int, int>> range_quries;
	for (int i = 0; i < n; i++) {
		cin >> l >> r >> v;
		update.emplace_back(make_pair(make_pair(l, r), v));
		indices.emplace_back(l);
		indices.emplace_back(r);
	}
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		range_quries.emplace_back(make_pair(l, r));
		indices.emplace_back(l);
		indices.emplace_back(r);
	}

	sort(begin(indices), end(indices));
	indices.resize(distance(
	  begin(indices), unique(begin(indices), end(indices))));

	n = indices.size();
	vector<int> width(n + 1), differece(n + 1),
	  prefix_sum(n + 1), interval(n + 1);
	for (auto p : update) {
		differece[find_index(indices, p.first.first)] += p.second;
		differece[find_index(indices, p.first.second)] -= p.second;
	}

	for (int i = 0; i < n - 1; i++)
		width[i + 1] = indices[i + 1] - indices[i];

	for (int i = 1; i < n; i++)
		interval[i] = interval[i - 1] + differece[i - 1];

	for (int i = 1; i < n; i++)
		prefix_sum[i] = prefix_sum[i - 1] + interval[i] * width[i];

	for (auto p : range_quries) {
		cout << prefix_sum[find_index(indices, p.second)]
				  - prefix_sum[find_index(indices, p.first)]
			 << endl;
	}
	return 0;
}