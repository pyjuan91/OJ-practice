#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, p;
	cin >> t;
	while (t--) {
		cin >> n >> p;
		int res = 0, ec = n - 1;
		vector<pair<int, int>> entries(n);
		vector<int> a(n);
		vector<bool> in_mst(n, false);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			entries[i] = make_pair(a[i], i);
		}
		sort(entries.rbegin(), entries.rend());
		while (!entries.empty()) {
			auto mi = entries.back().first, id = entries.back().second;
			entries.pop_back();
			if (mi >= p) break;
			int left = id, right = id;
			while (left - 1 >= 0 && !in_mst[left]
				   && a[left - 1] % a[id] == 0)
				left -= 1;
			while (right + 1 < n && !in_mst[right]
				   && a[right + 1] % a[id] == 0)
				right += 1;
			for (int i = left; i <= right; i++)
				in_mst[i] = true;
			res += mi * (right - left);
			ec -= right - left;
		}
		res += p * ec;
		cout << res << "\n";
	}
	return 0;
}