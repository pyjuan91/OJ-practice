#include <bits/stdc++.h>
using namespace std;
int chaewon(vector<int>& a, int& n) {
	int left = n / 2;
	while (left > 0 && a[left] < a[left + 1]) left -= 1;
	int right = n / 2 + 1 + (n & 1);
	while (right <= n && a[right] > a[right - 1]) right += 1;
	return max(left, n + 1 - right);
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> x, a[x] = i;
		cout << chaewon(a, n) << "\n";
	}
	return 0;
}