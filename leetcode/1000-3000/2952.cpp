#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int minimumAddedCoins(vector<int>& coins, int target) {
			int n = coins.size();
			sort(coins.begin(), coins.end());
			int success_obstainable = 0, ans = 0;
			for (int i = 0; i < n; i++) {
				if (coins[i] > target || success_obstainable >= target)
					break;
				while (coins[i] > success_obstainable + 1) {
					ans++;
					success_obstainable += success_obstainable + 1;
				}
				success_obstainable += coins[i];
			}
			while (success_obstainable < target) {
				ans++;
				success_obstainable += success_obstainable + 1;
			}
            return ans;
		}
};
int main() {
	Solution sol;
	int n, target;
	cin >> n >> target;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) cin >> coins[i];
	cout << sol.minimumAddedCoins(coins, target) << endl;
	return 0;
}