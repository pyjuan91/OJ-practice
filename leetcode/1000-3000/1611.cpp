#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int minimumOneBitOperations(int n) {
			auto steps
			  = [&](int id) { return (1LL << (id + 1)) - 1; };
			int res = 0, signs = 1;
			for (int i = 31; i >= 0; i--) {
				if (n & (1 << i))
					res += signs * steps(i), signs *= -1;
			}
			return res;
		}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	cout << s.minimumOneBitOperations(n) << endl;
	return 0;
}