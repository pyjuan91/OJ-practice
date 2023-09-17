#include <bits/stdc++.h>
#define int long long
using namespace std;
int cal(int guess, int c, int h) { return guess * (c + h) + h; }
bool check(int guess, int c, int h, int tar) {
	int su = cal(guess, c, h);
	return (su / (guess * 2 + 1)) >= tar;
}
int chaewon(int c, int h, int tar) {
	if (tar <= (h + c) / 2) return 2;
	int left = 0, right = 1e7, mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		// cout << "mid: " << mid << '\n';
		// cout << "check: " << check(mid, c, h, tar) << '\n';
		if (check(mid, c, h, tar)) left = mid;
		else right = mid;
	}
    double left_diff = abs((double)cal(left, c, h) / (left * 2 + 1) - tar);
    double right_diff = abs((double)cal(right, c, h) / (right * 2 + 1) - tar);
    if (left_diff <= right_diff) return left * 2 + 1;
    else return right * 2 + 1;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, c, h, tar;
	cin >> t;
	while (t--) {
		cin >> h >> c >> tar;
		cout << chaewon(c, h, tar) << '\n';
	}
	return 0;
}
