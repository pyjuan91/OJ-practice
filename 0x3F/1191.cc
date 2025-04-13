#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct MaxSumSubarray {
        int64_t sum = 0;
        size_t left_index = 0;
        size_t right_index = 0;
    };

    MaxSumSubarray getMaxSumSubarray(const vector<int>& arr)
    {
        MaxSumSubarray res;
        int64_t max_sum_so_far = 0;
        int64_t max_sum_all_time = 0;
        size_t left_index = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            max_sum_so_far += static_cast<int64_t>(arr[i]);
            if (max_sum_so_far < 0) {
                max_sum_so_far = 0;
                left_index = i + 1;
            }
            if (max_sum_so_far > max_sum_all_time) {
                max_sum_all_time = max_sum_so_far;
                res.left_index = left_index;
                res.right_index = i;
            }
        }
        res.sum = max_sum_all_time;
        return res;
    }

public:
    int kConcatenationMaxSum(vector<int>& arr, int k)
    {
        if (k == 1) {
            return static_cast<int>(getMaxSumSubarray(arr).sum);
        }

        size_t n = arr.size();

        vector<int64_t> left_prefix_sum(n + 1, 0L);
        vector<int64_t> right_prefix_sum(n + 1, 0L);
        int64_t left_maximum = 0L, right_maximum = 0L;

        for (size_t i = 0; i < n; i++) {
            left_prefix_sum[i + 1] = left_prefix_sum[i] + arr[n - 1 - i];
            right_prefix_sum[i + 1] = right_prefix_sum[i] + arr[i];
            left_maximum = max(left_maximum, left_prefix_sum[i + 1]);
            right_maximum = max(right_maximum, right_prefix_sum[i + 1]);
        }

        int64_t total_sum = accumulate(arr.begin(), arr.end(), 0L);
        int64_t max_sum = left_maximum + right_maximum + max(0L, total_sum * (k - 2));
        return max(max_sum, getMaxSumSubarray(arr).sum) % 1'000'000'007;
    }
};

int main() { return 0; }