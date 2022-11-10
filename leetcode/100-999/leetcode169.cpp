#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int major = INT_MAX;
        for (auto i : nums) {
            if (cnt == 0) {
                major = i;
                cnt++;
            } else {
                if (major == i)
                    cnt++;
                else
                    cnt--;
            }
        }
        return major;
    }
};
int main(void) {
    return 0;
}