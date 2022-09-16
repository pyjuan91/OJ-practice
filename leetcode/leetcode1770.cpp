#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int h1, h2, t1, t2, res = 0, n = multipliers.size(), pro1, pro2;
        h1 = 1, h2 = 0, t1 = n - 1, t2 = n - 2;
        vector<int> h(n), t(n);
        h[0] = multipliers[0] * nums[0];
        t[0] = multipliers[0] * nums[n - 1];
        // for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            pro1 = h[j - 1] + nums[h1] * multipliers[j];
            pro2 = t[j - 1] + nums[h2] * multipliers[j];
            pro2 = INT_MIN;
            cout << "h1: " << h1 << " h2: " << h2 << endl;
            cout << pro1 << " " << pro2 << endl;
            if (pro1 > pro2) {
                h1++;
                h[j] = pro1;
            } else {
                h2++;
                h[j] = pro2;
            }
            if (t1 != h1)
                pro1 = h[j - 1] + nums[t1] * multipliers[j];
            else
                pro1 = INT_MIN;
            if (t2 != h2)
                pro2 = t[j - 1] + nums[t2] * multipliers[j];
            else
                pro2 = INT_MIN;
            cout << "t1: " << t1 << " t2: " << t2 << endl;
            cout << pro1 << " " << pro2 << endl;
            if (pro1 > pro2) {  
                t1--;
                t[j] = pro1;
            } else {
                t2--;
                t[j] = pro2;
            }
            cout << h[j] << " " << t[j] << endl;
        }
        // }
        return max(h[n - 1], t[n - 1]);
    }
};
int main(void)
{
    Solution s;
    vector<int> nums = { 1, 2, 3 };
    vector<int> multipers = { 3, 2, 1 };
    cout << s.maximumScore(nums, multipers) << "\n";
    return 0;
}