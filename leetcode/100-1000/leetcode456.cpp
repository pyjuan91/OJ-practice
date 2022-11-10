#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// class Solution {
// private:
//     stack<pair<int, int>> mins, maxs;

// public:
//     bool find132pattern(vector<int>& nums)
//     {
//         if (nums.size() < 3)
//             return false;
//         while (!mins.empty())
//             mins.pop();
//         while (!maxs.empty())
//             maxs.pop();
//         mins.push(make_pair(nums[0], 0));
//         maxs.push(make_pair(nums[0], 0));

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] < mins.top().first) {
//                 mins.push(make_pair(nums[i], i));
//             } else if (nums[i] > maxs.top().first) {
//                 maxs.push(make_pair(nums[i], i));
//             }
//         }

//         for (int i = nums.size() - 1; i >= 2; i--) {cout << "i: " << nums[i] << " mins: " << mins.top().first << " " << mins.top().second << " maxs: " << maxs.top().first << " " << maxs.top().second << endl;
//             balance(i);
//             cout << "after balance i: " << nums[i] << " mins: " << mins.top().first << " " << mins.top().second << " maxs: " << maxs.top().first << " " << maxs.top().second << endl;
//             if (mins.empty() || maxs.empty()) {
//                 cout << "yoyo" << endl;
//                 return false;
//             }
//             if (nums[i] > mins.top().first /*&& nums[i] < maxs.top().first*/)
//                 return true;
//         }
//         return false;
//     }

//     void balance(int i)
//     {
//         while (!maxs.empty() && maxs.top().second >= i) {
//             maxs.pop();
//         }
//         while (!mins.empty() && !maxs.empty() && mins.top().second >= maxs.top().second) {
//             mins.pop();
//         }
//     }
// };
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums)
//     {
//         int i, j, k, findThree, findOne;
//         for (i = nums.size() - 1; i >= 0; i--) {
//             findThree = findOne = 0;
//             for (j = i - 1; j > 0; j--) {
//                 if (nums[j] > nums[i]) {
//                     findThree = 1;
//                     break;
//                 }
//             }
//             if (!findThree)
//                 continue;
//             for (k = j - 1; k >= 0; k--) {
//                 if (nums[k] < nums[i]) {
//                     findOne = 1;
//                     break;
//                 }
//             }
//             if (findOne)
//                 return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        stack<int> s;
        int c3 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < c3)
                return true;
            else
                while (!s.empty() && s.top() < nums[i]) {
                    c3 = s.top();
                    s.pop();
                }
            s.push(nums[i]);
        }
        return false;
    }
};

int main(void)
{
    Solution s;
    vector<int> v = { 1, 4, 0, -1, -2, -3, -1, -2 };
    cout << s.find132pattern(v) << endl;
    return 0;
}