#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty())
            return { -1, -1 };
        int start = 0, end = nums.size() - 1,
            left = 0, right = nums.size() - 1;
        if (target < nums[left] || target > nums[right])
            return { -1, -1 };

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else
                left = mid;
        }
        if (nums[left] == target) {
            start = left;
        } else if (nums[right] == target) {
            start = right;
        } else {
            return { -1, -1 };
        }
        left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else
                left = mid;
        }
        if (nums[right] == target) {
            end = right;
        } else if (nums[left] == target) {
            end = left;
        }
        return { start, end };
    }
};
int main(void) { return 0; }