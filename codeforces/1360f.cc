#include <iostream>
#include <vector>
#define int long long
using namespace std;
int t, n, m;
string s[15];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> s[i];
		vector<vector<int>> diff(n);
		auto cal_diff = [&](string& s1, string& s2) {
			vector<int> res;
			for (int i = 0; i < m; i++) {
				if (s1[i] != s2[i]) res.emplace_back(i);
			}
			return res;
		};
		for (int i = 1; i < n; i++) {
			diff[i] = cal_diff(s[0], s[i]);
		}
		for (int i = 1; i < n; i++) {
			if (diff[i].size() > 2) {
				cout << "-1\n";
				goto end;
			}
			if (diff[i].size() == 0 || diff[i].size() == 1)
				continue;
			string check1 = s[0], check2 = s[0];
			check1[diff[i][0]] = s[i][diff[i][0]];
			check2[diff[i][1]] = s[i][diff[i][1]];
			bool all_pass = true;
			for (int j = 1; j < n; j++) {
				if (j == i) continue;
				if (cal_diff(check1, s[j]).size() > 1) {
					all_pass = false;
					break;
				}
			}
			if (all_pass) {
				cout << check1 << '\n';
				goto end;
			}
			all_pass = true;
			for (int j = 1; j < n; j++) {
				if (j == i) continue;
				if (cal_diff(check2, s[j]).size() > 1) {
					all_pass = false;
					break;
				}
			}
			if (all_pass) {
				cout << check2 << '\n';
				goto end;
			}
			cout << "-1\n";
			goto end;
		}
		cout << s[0] << '\n';
	end:;
	}
	return 0;
}
