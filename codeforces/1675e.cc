#include <bits/stdc++.h>
using namespace std;
string chaewon(int n, int k, string& s) {
	k = min(25, k);
	if (k == 25) return string(n, 'a');
	vector<vector<int>> pos(26, vector<int>());
	for (int i = 0; i < n; i++) pos[s[i] - 'a'].emplace_back(i);
	int smg = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] - 'a' == k) {
			string res = "";
			for (int j = 0; j < n; j++) {
				if (s[j] - 'a' <= k) res.push_back('a');
				else res.push_back(s[j]);
			}
			return res;
		}
		if (s[i] - 'a' > k) {
			string res = "";
			if (smg == -1) {
				for (int j = 0; j < n; j++) {
					if (s[j] <= s[i] && s[j] >= s[i] - k)
						res.push_back(s[i] - k);
					else res.push_back(s[j]);
				}
			}
			else {
				int quota = k - smg;
				for (int j = 0; j < n; j++) {
					if (s[j] - 'a' <= smg) res.push_back('a');
					else if (s[j] <= s[i] && s[j] >= s[i] - quota)
						res.push_back(s[i] - quota);
					else res.push_back(s[j]);
				}
			}
			return res;
		}
		smg = max(s[i] - 'a', smg);
	}
	return string(n, 'a');
}
int main() {
	int t, n, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		cout << chaewon(n, k, s) << "\n";
	}
	return 0;
}