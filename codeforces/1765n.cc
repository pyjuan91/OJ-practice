#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> s >> k;
		n = s.length();
		vector<vector<int>> digit_pos(10);
		for (int i = n - 1; i >= 0; i--)
			digit_pos[s[i] - '0'].emplace_back(i);
		string ans = "";
		int len = n - k, current = 0;
		for (int i = 0; i < len; i++) {
			for (int j = (i == 0); j < 10; j++) {
				while (!digit_pos[j].empty() && digit_pos[j].back() < current)
					digit_pos[j].pop_back();
				if (!digit_pos[j].empty() && n - digit_pos[j].back() >= len - i) {
					ans.push_back((char) (j + '0'));
					current = digit_pos[j].back() + 1;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}