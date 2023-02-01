#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool isDiv(string& big, string& small) {
			if (big.length() % small.length() != 0)
				return false;
			for (int i = 0; i < big.length(); i += small.length()) {
				for (int j = i; j < i + small.length(); j++)
					if (big[j] != small[j - i])
						return false;
			}
			return true;
		}
		string gcdOfStrings(string str1, string str2) {
			string res = "", cur = "";
			if (str2.size() > str1.size())
				swap(str1, str2);
			for (int i = 0; i < str2.size(); i++) {
				if (str1[i] != str2[i]) break;
				cur = cur + str1[i];
				if (isDiv(str1, cur) && isDiv(str2, cur))
					res = cur;
			}
			return res;
		}
};
int main() { return 0; }