#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int cnt, n = nums.size(), checker = 0, j;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                j = i, cnt = 0, checker = 0;
                while (j >= 0) {
                    if (nums[j] > cnt) {
                        checker = 1;
                        break;
                    }
                    j--, cnt++;
                }
                if (checker == 0)
                    return false;
                i = j + 1;
            }
        }
        return true;
    }
};
int main(void) { return 0; }