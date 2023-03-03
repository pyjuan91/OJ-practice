#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t, n, k, ans;
	string str;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cin >> str;
		map<char, int> m;
		for (auto c : str) m[c] += 1;
		int couldBeUsed = 0;
		int remain = 0;
		for (auto p : m) {
			if (p.second % 2 == 0)
				couldBeUsed += p.second;
			else {
				couldBeUsed += p.second - 1;
				remain += 1;
			}
		}
		couldBeUsed /= 2;
		ans = couldBeUsed / k;
		ans *= 2;
		if (remain + (couldBeUsed % k) * 2 >= k)
			ans += 1;
		cout << max(ans, 1) << "\n";
	}
	return 0;
}