#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back({ nums[i], i });
        sort(v.begin(), v.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            long long cur = 
            (long long)v[left].first + (long long)v[right].first;
            if (cur == (long long)target) {
                return vector<int> { v[left].second, v[right].second };
            } else if (cur < (long long)target) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return vector<int>();
    }
};
int main(void) { return 0; }