#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {   
        int max_product_all_time = nums[0], max_product_so_far = 1;
        int min_product_all_time = nums[0], min_product_so_far = 1;
        for (const auto& num : nums) {
            if (num < 0) {
                swap(max_product_so_far, min_product_so_far);
            }
            max_product_so_far = max(num, max_product_so_far * num);
            min_product_so_far = min(num, min_product_so_far * num);
            max_product_all_time = max(max_product_all_time, max_product_so_far);
            min_product_all_time = min(min_product_all_time, min_product_so_far);
        }
        return max(max_product_all_time, min_product_all_time);
    }
};

int main() { return 0; }