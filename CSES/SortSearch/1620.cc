#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(vector<int> &a, int guess, int t) {
	int res = 0;
	for (auto x : a) {
		res += guess / x;
		if (res >= t) return true;
	}
	return false;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	int left = 0, right = INT64_MAX;
	while (left + 1 < right) {
		int mid = left + (right - left) / 2;
		if (check(a, mid, t)) right = mid;
		else left = mid;
	}
	cout << right;
	return 0;
}