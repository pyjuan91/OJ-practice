#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getMaxSplicedArray(const vector<int>& arr1, const vector<int>& arr2)
    {
        size_t n = arr1.size();
        vector dp(n, vector(3, 0));
        // dp[i][0]: ending with arr1[i] and pure arr1
        // dp[i][1]: ending with arr1[i] and can have arr2[i] before
        // dp[i][2]: ending with arr2[i]
        dp[0][0] = arr1[0];
        dp[0][1] = max(arr1[0], arr2[0]);
        dp[0][2] = arr2[0];

        for (size_t i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + arr1[i];
            dp[i][1] = arr1[i] + max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = arr2[i] + max(dp[i - 1][0], dp[i - 1][2]);
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }

public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2)
    {
        return max(
            getMaxSplicedArray(nums1, nums2),
            getMaxSplicedArray(nums2, nums1));
    }
};

int main() { return 0; }