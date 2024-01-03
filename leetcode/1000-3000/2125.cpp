#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int numberOfBeams(vector<string>& bank) {
			int prev = 0, sum = 0, cur;
			for (const auto& s : bank) {
				cur = count(s.begin(), s.end(), '1');
				if (cur == 0) continue;
				if (prev == 0) {
					prev = cur;
					continue;
				}
				sum += prev * cur;
				prev = cur;
			}
            return sum;
		}
};
int main() {
	Solution sol;
	int n;
	cin >> n;
	vector<string> bank(n);
	for (int i = 0; i < n; i++) { cin >> bank[i]; }
	cout << sol.numberOfBeams(bank) << endl;
	return 0;
}