#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1, spin = 0;
        while (nums[left] > nums[right] && left + 1 < right) {
            spin = left + (right - left) / 2;
            if (nums[spin] > nums[left])
                left = spin;
            else
                right = spin;
        }
        int l, r;
        if (spin == 0) {
            if (nums[left] < nums[right])
                left = nums.size() - 1, right = 0;
        }
        if (target < nums[right] || target > nums[left]
            || (target > nums[nums.size() - 1] && target < nums[0]))
            return -1;

        if (target == nums[0])
            return 0;
        else if (target >= nums[0]) {
            l = 0, r = left;
        } else {
            l = right, r = nums.size() - 1;
        }
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (target == nums[l])
            return l;
        if (target == nums[r])
            return r;
        return -1;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = { 1, 3, 5 };
    Solution s;
    cout << s.search(nums, 5) << endl;
    return 0;
}