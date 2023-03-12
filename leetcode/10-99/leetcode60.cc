#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		string getPermutation(int n, int k) {
			vector<int> v(n);
			for (int i = 0; i < n; i++)
				v[i] = i + 1;
			do {
				k--;
			} while (k > 0
					 && next_permutation(v.begin(), v.end()));
			string res = "";
			for (auto i: v) res += to_string(i);
			return res;
		}
};
int main() {
	auto s = Solution();
	cout << s.getPermutation(4, 9) << endl;
	return 0;
}