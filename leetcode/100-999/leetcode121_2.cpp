#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        vector<int> min;
        int mp = prices[0];
        for (auto i : prices) {
            if (i < mp)
                mp = i;
            min.push_back(mp);
        }
        int ans = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - min[i]);
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}