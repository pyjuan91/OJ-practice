#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k, x;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.emplace_back(make_pair(x, i));
		}
		vector<int> b, res(n);
		for (int i = 0; i < n; i++) {
			cin >> x;
			b.emplace_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++) res[a[i].second] = b[i];
		for (int i = 0; i < n; i++) cout << res[i] << " ";
		cout << "\n";
	}
	return 0;
}