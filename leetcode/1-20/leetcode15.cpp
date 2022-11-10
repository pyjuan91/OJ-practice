#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
// class Solution {
// public:
//     vector< vector<int> > threeSum(vector<int>& nums)
//     {
//         vector< vector<int> > ans;
//         vector<int> sol;
//         set< vector<int> >s;
//         if (nums.size() < 3)
//             return ans;
//         for (int i = 0; i < nums.size(); i++) {
//             sol.push_back(nums[i]);
//             for (int j = i + 1; j < nums.size(); j++) {
//                 sol.push_back(nums[j]);
//                 int check = 0 - nums[i] - nums[j];
//                 for (int k = j + 1; k < nums.size(); k++) {
//                     if (nums[k] == check) {
//                         cout << k << " "<<endl;
//                         sol.push_back(nums[k]);
//                         ans.push_back(sol);
//                         sol.pop_back();
//                     }
//                 }
//                 sol.pop_back();
//             }
//             sol.pop_back();
//         }
//         for(int i=0;i<ans.size();i++){
//             sort(ans[i].begin(), ans[i].end());
//             s.insert(ans[i]);
//         }
//         ans.clear();
//         for(auto i: s){
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // first sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int len = nums.size();
        for (int num1Idx = 0; num1Idx < len - 2; num1Idx++) {
            int num2Idx = num1Idx + 1;
            int num3Idx = len - 1;

            if (num1Idx > 0 && nums[num1Idx] == nums[num1Idx - 1]) {
                continue;
            }

            while (num2Idx < num3Idx) {
                int sum = nums[num1Idx] + nums[num2Idx] + nums[num3Idx];
                if (sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[num1Idx]);
                    tmp.push_back(nums[num2Idx]);
                    tmp.push_back(nums[num3Idx]);
                    ans.push_back(tmp);
                    num3Idx -= 1;
                    while (num2Idx < num3Idx && nums[num3Idx] == nums[num3Idx + 1]) {
                        num3Idx--;
                    }
                } else if (sum > 0) {
                    num3Idx--;
                } else {
                    num2Idx++;
                }
            }
        }
        return ans;
    }
};
int main(void)
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);

    Solution s;
    vector<vector<int>> vv;
    vv = s.threeSum(nums);
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}