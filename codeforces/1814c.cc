#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, s1, s2, x;
	cin >> t;
	while (t--) {
		cin >> n >> s1 >> s2;
		vector<pair<int, int>> r;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			r.emplace_back(make_pair(x, i));
		}
		sort(r.rbegin(), r.rend());
		vector<int> a, b;
		for (auto& p : r) {
			int time_a = (a.size() + 1) * s1;
			int time_b = (b.size() + 1) * s2;
			if (time_a < time_b) a.emplace_back(p.second);
			else b.emplace_back(p.second);
		}
		cout << a.size();
		for (auto& x : a) cout << " " << x;
		cout << "\n" << b.size();
		for (auto& x : b) cout << " " << x;
		cout << "\n";
	}
	return 0;
}