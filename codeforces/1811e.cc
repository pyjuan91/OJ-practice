#include <bits/stdc++.h>
using namespace std;
#define int long long
const int digit[9] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
int chaewon(int n) {
	vector<int> res;
	while (n) {
		res.emplace_back(digit[n % 9]);
		n /= 9;
	}
	int ans = 0;
	while (!res.empty()) {
		ans *= 10;
		ans += res.back();
		res.pop_back();
	}
	return ans;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << chaewon(n) << "\n";
	}
	return 0;
}