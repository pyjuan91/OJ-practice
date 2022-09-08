#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int sum = 0, ma = INT_MIN;
        for (int& i : nums) {
            if (sum >= 0)
                sum += i;
            else
                sum = i;
            ma = max(ma, sum);
        }
        return ma;
    }
};
int main(void)
{
    return 0;
}