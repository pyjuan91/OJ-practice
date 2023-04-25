#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, ma, sum;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		if (n % 2) {
			cout << "-1\n";
			continue;
		}
		vector<int> a(26), b(26);
		for (auto c : s) a[c - 'a'] += 1;
		for (auto i : a)
			if (i > n / 2) {
				cout << "-1\n";
				goto chaewon;
			}

		for (int i = 0; i < n / 2; i++)
			if (s[i] == s[n - 1 - i]) b[s[i] - 'a'] += 1;

		ma = sum = 0;
		for (auto i : b) {
			ma = max(ma, i);
			sum += i;
		}
		cout << max(ma, (sum + 1) / 2) << "\n";

	chaewon: {}
	}
	return 0;
}