#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x, out;
	cin >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			a[i].push_back(x);
		}
	}
	cin >> out;
	vector<pair<int, int>> res;
	for (int i = 0; i < n; i++) {
		bool contain = false;
		for (auto& x : a[i])
			if (x == out) contain = true;
		if (contain) res.push_back(make_pair(a[i].size(), i));
	}
	sort(res.begin(), res.end());
	if (res.size() == 0) cout << "0\n";
	else {
		int mi = res[0].first;
		while (!res.empty() && res.back().first > mi)
			res.pop_back();
        cout << res.size() << "\n";
        for (auto& x : res) cout << x.second + 1 << " ";
	}
	return 0;
}
