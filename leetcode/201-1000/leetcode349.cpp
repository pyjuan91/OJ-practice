#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s, ss;
        vector<int> ans;
        for (auto i : nums1) {
            s.insert(i);
        }
        for (auto i : nums2) {
            ss.insert(i);
        }
        for (auto i : ss) {
            if (s.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}