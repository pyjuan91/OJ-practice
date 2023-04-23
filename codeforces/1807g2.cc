#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		if (a[0] != 1) cout << "NO\n";
		else {
			int sum = 1;
			for (int i = 1; i < n; i++) {
				if (a[i] > sum) {
					cout << "NO\n";
					goto chaewon;
				}
				sum = min(sum + a[i], 200000);
			}
			cout << "YES\n";
		chaewon: {}
		}
	}
	return 0;
}