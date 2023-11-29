#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<string> removeInvalidParentheses(string s) {
			vector<string> ans;
			int nice_len = 0;
			chaewon(s, ans, nice_len);
			int ma_len = 0;
			for (auto str : ans) {
				ma_len = max(ma_len, (int) str.size());
			}
			vector<string> res;
			for (auto str : ans) {
				if (str.size() == ma_len) res.push_back(str);
			}
			return res;
		}
		bool isValid(string s) {
			int left = 0;
			for (auto c : s) {
				if (c == '(') left++;
				else if (c == ')') {
					if (left == 0) return false;
					left--;
				}
			}
			return left == 0;
		}
		unordered_set<string> st;
		void chaewon(string s, vector<string>& ans, int& nice_len) {
			if (s.size() < nice_len) return;
			if (st.count(s)) return;
			st.insert(s);
			if (isValid(s)) {
				ans.push_back(s);
				nice_len = max(nice_len, (int) s.size());
				return;
			}
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '(' || s[i] == ')') {
					string tmp = s.substr(0, i) + s.substr(i + 1);
					chaewon(tmp, ans, nice_len);
				}
			}
		}
};
int main() {
	Solution s;
	string str;
	cin >> str;
	vector<string> ans = s.removeInvalidParentheses(str);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}