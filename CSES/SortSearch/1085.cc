#include <bits/stdc++.h>
#define int long long
using namespace std;
bool chaewon(int k, vector<int> &a, int guess) {
	int cur = 0;
	for (auto x : a) {
		if (x > guess) return false;
		if (cur + x > guess) cur = x, k -= 1;
		else cur += x;
	}
	return k > 0;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	int left = 0, right = INT64_MAX, mid;
	while (left + 1 < right) {
		mid = left + (right - left) / 2;
		if (chaewon(k, a, mid)) right = mid;
		else left = mid;
	}
	cout << right;
	return 0;
}