#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
			unordered_set<string> s(wordList.begin(), wordList.end());
			unordered_set<string> vis = {beginWord};
			if (beginWord == endWord) return 1;
			if (!s.count(endWord)) return 0;
			int len = beginWord.size();
			queue<string> q;
			int dis = 0;
			q.push(beginWord);
			while (!q.empty()) {
				dis++;
				int sz = q.size();
				vector<string> clr;
				while (sz--) {
					string cur = q.front();
					clr.emplace_back(cur);
					q.pop();
					for (int i = 0; i < len; i++) {
						char tmp = cur[i];
						for (char c = 'a'; c <= 'z'; c++) {
							cur[i] = c;
							if (cur == endWord) return dis + 1;
							if (s.count(cur) && !vis.count(cur)) {
								q.push(cur);
								vis.insert(cur);
							}
						}
						cur[i] = tmp;
					}
				}
				for (auto &x : clr) s.erase(x);
			}
			return 0;
		}
};
int main() {
	Solution s;
	return 0;
}