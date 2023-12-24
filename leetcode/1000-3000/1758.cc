#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int cost(const string& s1, const string& s2) {
			int res = 0;
			for (int i = 0; i < s1.length(); i++)
				res += s1[i] != s2[i];
			return res;
		}
		int minOperations(string s) {
			int n = s.size();
			string s1, s2;
			for (int i = 0; i < n; i++) {
				s1.push_back(i % 2 ? '1' : '0');
				s2.push_back(i % 2 ? '0' : '1');
			}
			return min(cost(s, s1), cost(s, s2));
		}
};
int main() {
	Solution s;
	return 0;
}