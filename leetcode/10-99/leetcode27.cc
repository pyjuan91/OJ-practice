#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int res = 0;
        for (int& i : nums) {
            if (i != val) {
                swap(nums[res], i);
                res += 1;
            }
        }
        return res;
    }
};
int main(void) { return 0; }