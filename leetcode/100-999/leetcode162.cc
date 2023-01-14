#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return 0;
            if (nums[0] > nums[1]) return 0;
            if (nums[n - 1] > nums[n - 2]) return n - 1;
            int left = 0, right = n - 1, mid;
            while (left + 1 < right) {
                mid = left + (right - left) / 2;
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid;
                else if (nums[mid] > nums[mid - 1])
                    left = mid;
                else
                    right = mid;
            }
            if (nums[left] > nums[left - 1] && nums[left] > nums[left + 1])
                return left;
            return right;
        }
};
int main(void) {
    vector<int> nums = {1, 8, 2, 3, 4, 5, 6, 7};
    Solution s;
    cout << s.findPeakElement(nums);
    return 0;
}