#include <bits/stdc++.h>
#define int long long
using namespace std;
bool chaewon(int& n, int& m, vector<int>& a, vector<int>& b, int r) {
	int ia = 0, ib = 0;
	while (ia < n && ib < m) {
		if (a[ia] >= b[ib] - r && a[ia] <= b[ib] + r) ia += 1;
		else if (a[ia] < b[ib] - r) return false;
		else ib += 1;
	}
	return ia == n;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	a.resize(distance(a.begin(), unique(a.begin(), a.end())));
	b.resize(distance(b.begin(), unique(b.begin(), b.end())));
	n = a.size(), m = b.size();
	int left = -1, right = 3e9, mid;
	while (left + 1 < right) {
		mid = left + (right - left) / 2;
		if (chaewon(n, m, a, b, mid)) right = mid;
		else left = mid;
	}
	cout << right << "\n";
	return 0;
}