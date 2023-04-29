#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, cnt;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		cnt = 0;
		for (auto& x : a) {
			cin >> x;
			if (x == 1) cnt += 1;
		}
		if (a == vector<int>(n, a[0])) {
			cout << "0\n";
			continue;
		}
		if (cnt) {
			cout << "-1\n";
			continue;
		}
		vector<pair<int, int>> res;
		while (a != vector<int>(n, a[0])) {
			int left = 0, right = 1;
			while (a[left] == a[right]) right += 1;
			if (a[left] < a[right]) swap(left, right);
			a[left] = ceil((float(a[left]) / a[right]));
			res.emplace_back(make_pair(left + 1, right + 1));
		}

		cout << res.size() << "\n";
		for (auto& p : res)
			cout << p.first << " " << p.second << "\n";
	}
	return 0;
}