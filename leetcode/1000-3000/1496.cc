#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		bool isPathCrossing(string path) {
			pair<int, int> cur = {0, 0};
			set<pair<int, int>> s = {cur};
			for (const auto& c : path) {
				if (c == 'N') cur.first++;
				else if (c == 'S') cur.first--;
				else if (c == 'E') cur.second++;
				else if (c == 'W') cur.second--;
				if (s.count(cur)) return true;
				s.insert(cur);
			}
			return false;
		}
};
int main() {
	Solution s;
	return 0;
}