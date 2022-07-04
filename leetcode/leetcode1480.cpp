#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        size_t len = nums.size();
        for (int i = 1; i < len; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
int main(void)
{
    return 0;
}