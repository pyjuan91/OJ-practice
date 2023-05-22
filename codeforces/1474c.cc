#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, init, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(2 * n);
		for (auto &x : a) cin >> x;
		sort(a.begin(), a.end());
		for (int i = 0; i < 2 * n - 1; i++) {
			init = x = a[2 * n - 1] + a[i];
			multiset<int> ms(a.begin(), a.end());
			vector<pair<int, int>> res;
			while (!ms.empty()) {
				auto iter = ms.end();
				iter--;
				auto complement = ms.find(x - *iter);
				if (complement == ms.end() || complement == iter) {
					break;
				}
				else {
					res.emplace_back(make_pair(x - *iter, *iter));
					x = *iter;
					ms.erase(iter);
					ms.erase(complement);
				}
			}
			if (ms.empty()) {
				cout << "YES\n" << init << "\n";
				for (auto p : res)
					cout << p.first << " " << p.second << "\n";
				goto chaewon;
			}
		}
		cout << "NO\n";
	chaewon:;
	}
	return 0;
}