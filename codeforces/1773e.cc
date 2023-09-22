#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, sz, x, split = 0;
	cin >> n;
	vector<vector<int>> a(n);
	vector<int> sorted_result;
	unordered_map<int, int> nxt;
	for (int i = 0; i < n; i++) {
		cin >> sz;
		while (sz--) {
			cin >> x;
			a[i].emplace_back(x);
			sorted_result.emplace_back(x);
		}
		reverse(a[i].begin(), a[i].end());
	}
	sort(sorted_result.begin(), sorted_result.end());
	for (int i = 1; i < sorted_result.size(); i++) {
		nxt[sorted_result[i - 1]] = sorted_result[i];
	}
	for (auto& v : a) {
		int groups = 0;
		while (!v.empty()) {
			groups++;
			int x = v.back();
			v.pop_back();
			while (!v.empty() && nxt[x] == v.back()) {
				x = v.back();
				v.pop_back();
			}
		}
		split += groups - 1;
	}
	cout << split << ' ' << split + n - 1 << '\n';
	return 0;
}
