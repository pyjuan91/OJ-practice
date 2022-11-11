#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int noDup = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                res.push_back(nums[i]);
                noDup += 1;
            }
        }
        swap(nums, res);
        return noDup;
    }
};
int main(void)
{
    return 0;
}