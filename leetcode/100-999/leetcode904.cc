#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int totalFruit(vector<int>& fruits) {
			unordered_map<int, int> m;
			int left, right, res = 0;
			for (left = right = 0; right < fruits.size(); right++) {
				m[fruits[right]] += 1;
				while (m.size() > 2) {
					m[fruits[left]] -= 1;
					if (m[fruits[left]] == 0) {
						m.erase(fruits[left]);
					}
					left += 1;
				}
				res = max(res, right - left + 1);
			}
			return res;
		}
};
int main() { return 0; }