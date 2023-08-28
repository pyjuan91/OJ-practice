#include <bits/stdc++.h>
using namespace std;
struct Range {
		int l, r, id;
		Range(int l, int r, int id)
		  : l(l)
		  , r(r)
		  , id(id) {}
		Range() {}
		bool operator<(const Range& rhs) const {
			if (l != rhs.l) return l < rhs.l;
			return r < rhs.r;
		}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tt, n;
	string s, t[15];
	cin >> tt;
	while (tt--) {
		cin >> s >> n;
		int len = s.length();
		set<Range> ranges;
		for (int i = 1; i <= n; i++) {
			cin >> t[i];
			int l = t[i].length();
			auto it = s.find(t[i], 0);
			while (it != string::npos) {
				ranges.insert(Range(it, it + l, i));
				it = s.find(t[i], it + 1);
			}
		}
		int res = 0, bound = 0;
		auto beg = ranges.begin();
		vector<pair<int, int>> ans;
		while (bound < len) {
			auto it = ranges.upper_bound(Range(bound, INT32_MAX, 0));
			int right_most = 0, id = -1;
			while (beg != it) {
				if (beg->r > right_most) {
					right_most = beg->r;
					id = beg->id;
				}
				beg++;
			}
			if (id == -1) {
				res = -1;
				break;
			}
			bound = right_most;
			res++;
			ans.push_back({id, right_most - t[id].length()});
		}
		cout << res << '\n';
		if (res != -1) {
			for (auto i : ans)
				cout << i.first << " " << i.second + 1 << '\n';
		}
	}
	return 0;
}