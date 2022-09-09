#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        bool isNeg = false;
        int posLen = 0, negLen = 0, n = nums.size(), res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                posLen = negLen = 0;
            } else if (nums[i] > 0) {
                posLen++;
                if (negLen > 0)
                    negLen++;
            } else {
                swap(posLen, negLen);
                if (posLen > 0)
                    posLen++;
                negLen++;
            }
            res = max(res, posLen);
        }
        return res;
    }
};
int main(void)
{
    Solution s;
    vector<int> v = { 0, 1, -2, -3, -4 };
    s.getMaxLen(v);
    return 0;
}