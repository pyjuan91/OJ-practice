#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};
int main(void)
{
    vector<int> num = { 1, 2, 3 };
    do {
        for (int i = 0; i < 3; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
    } while (next_permutation(num.begin(), num.end()));
    for (int i = 0; i < 3; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}