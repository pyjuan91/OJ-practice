#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0, right = nums.size() - 1;
            if (nums.size() == 1) return nums[0];
            if (nums[right] > nums[left]) return nums[0];
            if (nums.size() == 2) return nums[1];
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > nums[left])
                    left = mid;
                else
                    right = mid;
            }
            return nums[right];
        }
};
int main(void) { return 0; }