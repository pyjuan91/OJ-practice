#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool isAlienSorted(vector<string>& words, string order) {
			map<char, char> dic;
			for (int i = 0; i < 26; i++) {
				dic[order[i]] = (char) ('a' + i);
			}
			for (auto& word : words)
				for (auto& ch : word) ch = dic[ch];
			vector<string> sorted_words = words;
			sort(sorted_words.begin(), sorted_words.end());
			return sorted_words == words;
		}
};
int main() { return 0; }