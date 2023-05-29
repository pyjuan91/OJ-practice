#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		int sum = 0, pos_num = 0, neg_num = 0;
		for (auto& x : a) {
			cin >> x, sum += x;
			if (x == 1) pos_num += 1;
			else if (x == -1) neg_num += 1;
		}
		if (sum % 2 == 1 || sum % 2 == -1) {
			cout << "-1\n";
			continue;
		}
		if (sum == 0) {
			cout << n << "\n";
			for (int i = 1; i <= n; i++)
				cout << i << " " << i << "\n";
		}
		else if (sum > 0) {
			vector<pair<int, int>> ans;
			int waiting = sum / 2;
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) {
					if (waiting) {
						if (ans.empty()) {
							ans.emplace_back(make_pair(i, i));
						}
						else if (ans.back().first == ans.back().second) {
							ans.back().second = i;
							waiting -= 1;
						}
						else {
							ans.emplace_back(make_pair(i, i));
						}
					}
					else ans.emplace_back(make_pair(i, i));
				}
				else ans.emplace_back(make_pair(i, i));
			}
			cout << ans.size() << "\n";
			for (auto p : ans)
				cout << p.first + 1 << " " << p.second + 1 << "\n";
		}
		else {
			vector<pair<int, int>> ans;
			int waiting = 0 - sum / 2;
			for (int i = 0; i < n; i++) {
				if (a[i] == -1) {
					if (waiting) {
						if (ans.empty()) {
							ans.emplace_back(make_pair(i, i));
						}
						else if (ans.back().first == ans.back().second) {
							ans.back().second = i;
							waiting -= 1;
						}
						else {
							ans.emplace_back(make_pair(i, i));
						}
					}
					else ans.emplace_back(make_pair(i, i));
				}
				else ans.emplace_back(make_pair(i, i));
			}
			cout << ans.size() << "\n";
			for (auto p : ans)
				cout << p.first + 1 << " " << p.second + 1 << "\n";
		}
	}
	return 0;
}