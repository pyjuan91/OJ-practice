#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> odd, even;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x & 1) odd.emplace_back(x);
			else even.emplace_back(x);
		}
		if (odd.empty() || even.empty()) cout << "YES\n";
		else {
			sort(odd.begin(), odd.end());
			sort(even.begin(), even.end());
			if (even[0] > odd[0]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}