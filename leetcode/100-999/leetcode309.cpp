#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0, low = prices[0], n = prices.size(), earn = 0;
        vector<int> buy(n), rest(n), sell(n);
        buy[0] = 0 - prices[0], rest[0] = 0, sell[0] = 0;
        for (int i = 1; i < n; i++) {
            buy[i] = max(rest[i - 1] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
            rest[i] = max(max(rest[i - 1], buy[i - 1]), sell[i - 1]);
            cout << "i: " << i << " price: " << prices[i] << " buy: " << buy[i] << " sell: " << sell[i] << " rest: " << rest[i] << endl;
        }
        return max(max(buy[n - 1], sell[n - 1]), rest[n - 1]);
    }
};
int main(void)
{
    Solution s;
    vector<int> prices = { 0,1, 2, 4, 3, 5, 6 };
    s.maxProfit(prices);
    return 0;
}