#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<string> ans;
		vector<string> restoreIpAddresses(string s) {
			ans.clear();
			go(s, 0, 0, "");
			return ans;
		}
		void go(const string& s, int cur_id, int cur_cnt, string cur_str) {
			if (cur_id == 4 && cur_cnt == s.size()) {
				ans.push_back(cur_str);
				return;
			}
			if (cur_id == 4 || cur_cnt == s.size()) return;
			if (cur_id != 0) cur_str += ".";
			for (int i = 1; i <= 3; i++) {
				if (cur_cnt + i > s.size()) break;
				string tmp = s.substr(cur_cnt, i);
				if (i == 2 && tmp[0] == '0') break;
				if (i == 3 && stoi(tmp) > 255) break;
				go(s, cur_id + 1, cur_cnt + i, cur_str + tmp);
			}
		}
};
int main() {
	Solution s;
	string str;
	cin >> str;
	vector<string> ans = s.restoreIpAddresses(str);
	for (auto i : ans) { cout << i << endl; }
	return 0;
}