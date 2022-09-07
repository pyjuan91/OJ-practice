#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int cnt = 1;
        if (nums.size() == 1)
            return 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i + nums[i] >= nums.size() - 1)
                return cnt;
            int ma = INT_MIN, id;
            for (int j = i + 1; j <= i + nums[i]; j++) {
                if (j + nums[j] > ma) {
                    ma = j + nums[j];
                    id = j;
                }
            }
            i = id - 1;
            cnt++;
        }
        return cnt;
    }
};
int main(void) { return 0; }