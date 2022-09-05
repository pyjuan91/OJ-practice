#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// class Solution {
// private:
//     queue<int> q;
//     int ma = INT_MIN;
//     int checker[100005] = {};

// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k)
//     {
//         vector<int> res;
//         int index = 0, cur;
//         for (int i = 0; i < k; i++) {
//             if (nums[i] >= ma) {
//                 index = i;
//                 ma = nums[i];
//             }
//         }
//         res.push_back(ma);
//         checker[index] = 1;
//         cur = 0;
//         for (int i = k; i < nums.size(); i++) {
//             if (checker[cur] == 1) {
//                 ma = INT_MIN;
//                 for (int j = i; j > i - k; j--) {
//                     if (nums[j] > ma) {
//                         ma = nums[j];
//                         index = j;
//                     }
//                 }
//                 checker[cur] = 0;
//                 index %= k;
//                 checker[index] == 1;
//             } else {
//                 if (nums[i] >= ma) {
//                     ma = nums[i];
//                     checker[index] = 0;
//                     index = cur;
//                     checker[cur] = 1;
//                 }
//             }
//             res.push_back(ma);
//             cur++;
//             cur %= k;
//         }
//         return res;
//     }
// };

class Solution {
private:
    int leftMax[100005], rightMax[100005];

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int i, j, ma, remain = nums.size() % k;
        for (i = 0; i < nums.size(); i += k) {
            ma = INT_MIN;

            for (j = i; j < nums.size() && j - i < k; j++) {
                ma = max(ma, nums[j]);
                leftMax[j] = ma;
            }
        }

        for (i = nums.size() - 1 - remain; i >= 0; i -= k) {

            ma = INT_MIN;

            for (j = i; j >= 0 && j > i - k; j--) {
                ma = max(ma, nums[j]);
                rightMax[j] = ma;
                // cout << "ma: " << ma << endl;
            }
        }

        // for (i = 0; i < nums.size(); i++) {
        //     cout << leftMax[i] << " ";
        // }
        // cout << endl;
        // for (i = 0; i < nums.size(); i++) {
        //     cout << rightMax[i] << " ";
        // }
        // cout << endl;
        ma = INT_MIN;
        for (i = nums.size() - 1; i >= nums.size() - remain; i--) {
            ma = max(ma, nums[i]);
            rightMax[i] = ma;
        }

        vector<int> res;
        for (i = 0; i <= nums.size() - k; i++) {
            res.push_back(max(rightMax[i], leftMax[i + k - 1]));
        }
        return res;
    }
};
int main(void)
{
    Solution s;
    vector<int> nums = { 1, -9, 8, -6, 6, 4, 0, 5 };
    nums = s.maxSlidingWindow(nums, 4);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}