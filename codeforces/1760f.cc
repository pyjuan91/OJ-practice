#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(int& n, int& c, int& d, vector<int>& a, int& guess) {
	int current = 0, sum = 0;
	for (int i = 0; i < d; i++) {
		if (current > guess) current = 0;
		if (current < n) sum += a[current];
		current += 1;
	}
	return sum >= c;
}
string chaewon(int& n, int& c, int& d, vector<int>& a) {
	sort(begin(a), end(a), greater<int>());
	if (a[0] * d < c) return "Impossible";
	int sum = 0;
	for (int i = 0; i < min(d, n); i++) sum += a[i];
	if (sum >= c) return "Infinity";

	int left = 0, right = 2e5 + 5;
	while (left + 1 < right) {
		int mid = left + (right - left) / 2;
		if (check(n, c, d, a, mid)) left = mid;
		else right = mid;
	}
	return to_string(left);
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, c, d;
	cin >> t;
	while (t--) {
		cin >> n >> c >> d;
		vector<int> a(n);
		for (auto& x : a) cin >> x;
		cout << chaewon(n, c, d, a) << "\n";
	}
	return 0;
}