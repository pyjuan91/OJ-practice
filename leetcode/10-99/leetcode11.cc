#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int sz = height.size();
        // int left_value = height[0], right_value = height[sz - 1];
        // int left_index = 0, right_index = sz - 1;
        // int chosen = min(left_value, right_value);
        // int ans = chosen * (right_index - left_index);
        // for (int i = 0; i < sz - 1; i++) {
        //     if (chosen == left_value && height[i] > left_value) {
        //         left_value = height[i];
        //         chosen = min(left_value, right_value);
        //         left_index = i;
        //         ans = max(ans, chosen * (right_index - left_index));
        //     }
        //     for (int j = sz - 1; j > i; j--) {
        //         if (chosen == right_value && height[j] > right_value) {
        //             right_value = height[j];
        //             chosen = min(left_value, right_value);
        //             right_index = j;
        //             ans = max(ans, chosen * (right_index - left_index));
        //         }
        //     }
        // }
        int ans = 0, left = 0, right = sz - 1, h;
        while (left < right) {
            h = min(height[left], height[right]);
            ans = max(ans, h * (right - left));
            while (height[left] <= h && left < right) {
                left++;
            }
            while (height[right] <= h && left < right) {
                right--;
            }
        }
        return ans;
    }
};

int main(void) { return 0; }