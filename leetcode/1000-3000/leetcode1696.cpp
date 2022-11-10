#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    deque<int> dq;

public:
    int maxResult(vector<int>& nums, int k)
    {
        int cur = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            cur = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);

            while (!dq.empty() && nums[dq.back()] < cur) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (dq.front() >= i + k)
                dq.pop_front();
            nums[i] = cur;
        }
        return cur;
    }
};
int main(void) { return 0; }