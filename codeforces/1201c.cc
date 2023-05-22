#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(vector<int> &a, int guess, int n, int k) {
	k -= guess - a[n / 2];
	for (int i = n / 2 + 1; i < n; i++) {
		if (a[i] < guess) k -= guess - a[i];
	}
	return k >= 0;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	int left = a[n / 2], right = a[n / 2] + k + 1;
	while (left + 1 < right) {
		int mid = left + (right - left) / 2;
		if (check(a, mid, n, k)) left = mid;
		else right = mid;
	}
	cout << left;
	return 0;
}