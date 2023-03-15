#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<int> grayCode(int n) {
			if (n == 1) return {0, 1};
			vector<int> prev = grayCode(n - 1);
			int len = prev.size(), d = pow(2, n - 1);
			for (int i = len - 1; i >= 0; i--)
				prev.emplace_back(d + prev[i]);
			return prev;
		}
};
int main() { return 0; }