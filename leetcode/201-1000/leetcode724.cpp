#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int pivot = -1;
        size_t sz = nums.size();
        for (size_t i = 1; i < sz; i++) {
            nums[i] += nums[i - 1];
        }
        for (size_t i = 1; i < sz; i++) {
            if (nums[i - 1] == nums[sz - 1] - nums[i]) {
                pivot = i;
                break;
            }
        }
        if (nums[sz - 1] == nums[0])
            pivot = 0;
        return pivot;
    }
};
int main(void)
{
    return 0;
}