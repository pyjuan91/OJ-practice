#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int max_sum_all_time = 0, max_sum_so_far = 0;
        int min_sum_all_time = 0, min_sum_so_far = 0;
        for (const auto& num : nums) {
            max_sum_so_far = max(0, max_sum_so_far + num);
            min_sum_so_far = min(0, min_sum_so_far + num);
            max_sum_all_time = max(max_sum_all_time, max_sum_so_far);
            min_sum_all_time = min(min_sum_all_time, min_sum_so_far);
        }
        return max(max_sum_all_time, -min_sum_all_time);
    }
};

int main() { return 0; }