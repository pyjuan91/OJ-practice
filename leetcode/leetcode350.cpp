#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        map<int, int> m;
        for (auto i : nums1) {
            if (!m[i]) {
                m[i] = 1;
            } else
                m[i] += 1;
        }
        for (auto i : nums2) {
            if (m[i]) {
                ans.push_back(i);
                m[i] -= 1;
            }
        }
        return ans;
    }
};
int main(void)
{
    vector<int> num1, num2;
    num1.push_back(1);
    num1.push_back(2);
    num1.push_back(2);
    num1.push_back(1);
    num2.push_back(2);
    num2.push_back(2);
    Solution s;
    s.intersect(num1, num2);
    return 0;
}