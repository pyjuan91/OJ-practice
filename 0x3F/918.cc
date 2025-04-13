#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        size_t n = nums.size();
        int boundary = *min_element(nums.begin(), nums.end());
        int max_sum_all_time = boundary, max_sum_so_far = 0;
        vector<int> prefix_sum(n, 0), max_prefix_sum(n, 0);
        vector<int> suffix_sum(n, 0), max_suffix_sum(n, 0);

        for (size_t i = 0; i < n; i++) {
            max_sum_so_far = max(nums[i], max_sum_so_far + nums[i]);
            max_sum_all_time = max(max_sum_all_time, max_sum_so_far);
            prefix_sum[i] = (i == 0 ? nums[i] : prefix_sum[i - 1] + nums[i]);
            max_prefix_sum[i] = (i == 0 ? nums[i] : max(max_prefix_sum[i - 1], prefix_sum[i]));
            suffix_sum[n - 1 - i] = (i == 0 ? nums[n - 1 - i] : suffix_sum[n - i] + nums[n - 1 - i]);
            max_suffix_sum[n - 1 - i] = (i == 0 ? nums[n - 1 - i] : max(max_suffix_sum[n - i], suffix_sum[n - 1 - i]));
        }

        int max_concatenated_sum = boundary;
        for (size_t i = 1; i < n; i++) {
            max_concatenated_sum = max(max_concatenated_sum, max_suffix_sum[i] + max_prefix_sum[i - 1]);
        }

        return max(max_sum_all_time, max_concatenated_sum);
    }
};

int main() { return 0; }