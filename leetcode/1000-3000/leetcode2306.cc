#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		long long distinctNames(vector<string>& ideas) {
			unordered_set<string> s[26];
			for (auto str : ideas) {
				string sub = str.substr(1);
				s[str[0] - 'a'].insert(sub);
			}
			long long res = 0;
			for (int i = 0; i < 25; i++) {
				for (int j = i + 1; j < 26; j++) {
					long long mut = 0;
					for (auto str : s[j]) {
						if (s[i].count(str)) mut += 1ll;
					}
					res += (1ll * s[i].size() - mut)
							 * (1ll * s[j].size() - mut);
				}
			}
			return res * 2ll;
		}
};
int main() {
	Solution s;
	vector<string> ideas;
	ideas.emplace_back("coffee");
	ideas.emplace_back("donuts");
	ideas.emplace_back("time");
	ideas.emplace_back("toffee");
	cout << s.distinctNames(ideas) << endl;
	return 0;
}