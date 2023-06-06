#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		set<int> s;
		while (n--) {
			cin >> x;
			s.insert(x);
		}
		if (s.size() <= 3) {
			cout << "0\n";
			continue;
		}
		int left = 0, right = 1e9;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			int quota = 3, cur_select = -1e9;
			for (auto iter : s) {
				if (llabs(iter - cur_select) > mid) {
					quota--;
					cur_select = iter + mid;
				}
			}
			if (quota < 0) left = mid;
			else right = mid;
		}
		cout << right << "\n";
	}
	return 0;
}