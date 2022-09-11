#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size(), low = prices[0], res = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] > low) {
                res += prices[i] - low;
            }
            low = prices[i];
        }
        return res;
    }
};
int main(void)
{
    return 0;
}