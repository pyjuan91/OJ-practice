#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t, n;
	string str;
	cin >> t;
	while (t--) {
		cin >> n >> str;
		long long res = 0;
		vector<int> a(n + 1);
		map<int, int> dic;
		dic[0] = 1;
		for (int i = 1; i <= n; i++)
			a[i] = str[i - 1] - '0';
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
			dic[a[i] - i] += 1;
		}
		for (auto pr : dic) {
			if (pr.second > 1)
				res += 1LL * pr.second * (pr.second - 1) / 2;
		}
		cout << res << "\n";
	}
	return 0;
}