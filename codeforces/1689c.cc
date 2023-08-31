#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>> v(n + 1);
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		vector<int> rank(n + 1, 0);
		function<int(int, int)> gen_rank = [&](int cur, int prev) {
			int res = 1;
			for (auto child : v[cur]) {
				if (child != prev) {
					res += gen_rank(child, cur);
				}
			}
			return rank[cur] = res;
		};
		gen_rank(1, 0);
		vector<int> left(n + 1, 0), right(n + 1, 0);
		function<void(int, int)> gen_tree = [&](int cur, int prev) {
			for (auto child : v[cur]) {
				if (child != prev) {
					if (left[cur] == 0) left[cur] = child;
					else right[cur] = child;
					gen_tree(child, cur);
				}
			}
		};
		gen_tree(1, 0);
		vector<int> score(n + 1, -1);
		function<int(int)> gen_score = [&](int root) {
			if (left[root] == 0 && right[root] == 0) return 0;
			if (score[root] != -1) return score[root];
			if (right[root] == 0)
				return score[root] = rank[left[root]] - 1;
			int cut_left = rank[left[root]] - 1 + gen_score(right[root]);
			int cut_right
			  = rank[right[root]] - 1 + gen_score(left[root]);
			return score[root] = max(cut_left, cut_right);
		};
		cout << gen_score(1) << '\n';
	}
	return 0;
}
