#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums)
    {
        vector<vector<int>> pf(1005);
        for (int i = 2; i <= 1000; i++) {
            if (pf[i].empty()) {
                for (int j = i; j <= 1000; j += i) {
                    pf[j].emplace_back(i);
                }
            }
        }
        unordered_set<int> res;
        for (auto i : nums) {
            for (auto j : pf[i])
                res.insert(j);
        }
        return res.size();
    }
};
int main(void) { return 0; }