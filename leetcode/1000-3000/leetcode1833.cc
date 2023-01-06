#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (auto i : costs) {
            if (coins >= i) {
                res += 1;
                coins -= i;
            }
            else return res;
        }
        return res;
    }
};
int main(void) { return 0; }