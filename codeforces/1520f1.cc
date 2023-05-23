#include <bits/stdc++.h>
using namespace std;
int chaewon(int left, int right, int k) {
	int mid = left + (right - left) / 2, cur;
	cout << "? " << left << " " << mid << "\n";
	cout.flush();
	cin >> cur;
	if (left == right) return left;
	if (left + 1 == right) {
		if (cur == 0 && k == 1) return left;
		return right;
	}
	if (mid - left + 1 - cur >= k) return chaewon(left, mid, k);
	else
		return chaewon(mid + 1, right, k - mid + left - 1 + cur);
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, t, k, res;
	cin >> n >> t >> k;
	res = chaewon(1, n, k);
	cout << "! " << res;
	return 0;
}