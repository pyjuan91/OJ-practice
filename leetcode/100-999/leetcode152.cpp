#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int res, mi, ma;
        res = mi = ma = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(ma, mi);
            }
            ma = max(nums[i] * ma, nums[i]);
            mi = min(nums[i] * mi, nums[i]);
            res = max(res, ma);
        }
        return res;
    }
};
int main(void) { return 0; }