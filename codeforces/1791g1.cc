#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m, i;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += i;
		}
		sort(a.begin(), a.end());
		for (i = 0; i < a.size() && m >= a[i]; m -= a[i++]) {}
		cout << i - 1 << "\n";
	}
	return 0;
}