#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> a, int avg) {
	int cur = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > avg) return false;
		else if (a[i] == avg) continue;
		else {
			if (i == a.size() - 1) return false;
			a[i + 1] += a[i];
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t, n, ans;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = n; i >= 1; i--) {
			if (sum % i != 0) continue;
			int avg = sum / i;
			if (check(a, avg)) {
				ans = n - i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}