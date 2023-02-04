#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool checkInclusion(string s1, string s2) {
			vector<int> a1(26, 0), a2(26, 0);
			if (s2.size() < s1.size()) return false;
			for (auto c : s1) a1[c - 'a'] += 1;
			for (int i = 0; i < s1.size(); i++)
				a2[s2[i] - 'a'] += 1;
			if (a1 == a2) return true;
			for (int i = 0; i < s2.size() - s1.size(); i++) {
				a2[s2[i] - 'a'] -= 1;
				a2[s2[i + s1.size()] - 'a'] += 1;
				if (a1 == a2) return true;
			}
			return false;
		}
};
int main() { return 0; }