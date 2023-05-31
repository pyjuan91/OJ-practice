#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (auto& x : a) cin >> x;
		for (auto x : a) cout << n + 1 - x << " ";
		cout << "\n";
	}
	return 0;
}