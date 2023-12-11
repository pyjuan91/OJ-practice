#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
			if (n1 + n2 != n3) return false;
			vector<bool> dp(n2 + 1, false);
			s1 = " " + s1, s2 = " " + s2, s3 = " " + s3;
			for (int s1_ins = 0; s1_ins <= n1; s1_ins++) {
				dp[0] = s1.substr(1, s1_ins) == s3.substr(1, s1_ins);
				for (int s2_ins = 1; s2_ins <= n2; s2_ins++) {
					int select_s1 = dp[s2_ins]
								 && s1[s1_ins] == s3[s1_ins + s2_ins];
					int select_s2 = dp[s2_ins - 1]
								 && s2[s2_ins] == s3[s1_ins + s2_ins];
					dp[s2_ins] = select_s1 || select_s2;
				}
			}
			return dp[n2];
		}
};
int main() {
	Solution s;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}