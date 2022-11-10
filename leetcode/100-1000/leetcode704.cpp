#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int low, mid, high;
        low = 0, high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
int main(void)
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(12);
    Solution s;
    cout << s.search(nums, 4) << endl;
    return 0;
}