#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool is_vowel(char& c) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				return true;
			return false;
		}
		int maxVowels(string s, int k) {
			auto left = 0, right = k;
			int res, vc = 0;
			for (int i = 0; i < k; i++) {
				if (is_vowel(s[i])) vc += 1;
			}
			res = vc;
			while (right < s.length()) {
				if (is_vowel(s[right])) {
					if (!is_vowel(s[left])) vc += 1;
				}
				else {
					if (is_vowel(s[left])) vc -= 1;
				}
				res = max(res, vc);
			}
			return res;
		}
};
int main() { return 0; }