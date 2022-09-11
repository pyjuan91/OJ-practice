#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size(), maxDiff = 0, mi = prices[0];
        for (int i = 1; i < n; i++) {
            maxDiff = max(maxDiff, prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        return maxDiff;
    }
};
int main(void) { return 0; }