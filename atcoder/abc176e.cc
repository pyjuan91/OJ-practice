#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int h, w, m;
	cin >> h >> w >> m;
	vector<set<int>> r(h), c(w);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		r[x].insert(y);
		c[y].insert(x);
	}
	int tar_r = 0, tar_c = 0;
	int ma_r = 0, ma_c = 0;
	for (int i = 0; i < h; i++) {
		if (r[i].size() > ma_r) {
			ma_r = r[i].size();
			tar_r = i;
		}
	}
	for (int j = 0; j < w; j++) {
		if (c[j].size() > ma_c) {
			ma_c = c[j].size();
			tar_c = j;
		}
	}
	vector<int> candi_r, candi_c;
	for (int i = 0; i < h; i++) {
		if (r[i].size() == ma_r) candi_r.push_back(i);
	}
	for (int i = 0; i < w; i++) {
		if (c[i].size() == ma_c) candi_c.push_back(i);
	}
	bool ok = false;
	for (auto x : candi_r) {
		for (auto y : candi_c) {
			if (r[x].count(y) == 0) {
				ok = true;
				break;
			}
		}
	}
	cout << ma_r + ma_c - (ok ? 0 : 1) << '\n';
	return 0;
}
