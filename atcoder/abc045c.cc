#include <bits/stdc++.h>
#define int long long
using namespace std;
int cal_slice(int n) {
	if (n == 0) return 1;
	return pow(2, n - 1);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0, len;
	cin >> n;
	vector<int> a;
	while (n) a.push_back(n % 10), n /= 10;
	len = a.size();
	for (int i = len - 1; i >= 0; i--) {
		for (int j = 1; j <= i + 1; j++) {
			int left = cal_slice(len - i);
			int right = cal_slice(i - j + 1);
			res += a[i] * pow(10, j - 1) * right * left;
		}
	}
	cout << res;
	return 0;
}
