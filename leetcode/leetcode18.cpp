#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.size() < 4) {
            return vector<vector<int>>();
        }
        set<vector<int>> s;
        vector<vector<int>> ans;
        long long longlongTarget = (long long)target, compare;
        int first, second, third, forth;
        sort(nums.begin(), nums.end());
        first = 0, forth = nums.size() - 1;
        for (first = 0; first < nums.size() - 3; first++) {
            for (forth = nums.size() - 1; forth > first + 2; forth--) {
                second = first + 1, third = forth - 1;
                while (second < third) {
                    compare = (long long)nums[first] + (long long)nums[second]
                        + (long long)nums[third] + (long long)nums[forth];
                    if (compare == longlongTarget) {
                        s.insert({ nums[first], nums[second], nums[third], nums[forth] });
                        second += 1;
                    } else if (compare > longlongTarget) {
                        third -= 1;
                    } else if (compare < longlongTarget) {
                        second += 1;
                    }
                }
            }
        }
        for (auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}