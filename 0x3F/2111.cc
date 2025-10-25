#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kIncreasing(vector<int>& arr, int k)
    {
        int res = 0;
        for (size_t i = 0; i < k; i++)
        {
            int list_size = 0;
            vector<int> lnds;
            for (size_t j = i; j < arr.size(); j += k)
            {
                list_size++;
                int x = arr[j];
                int idx = upper_bound(lnds.begin(), lnds.end(), x) - lnds.begin();
                if (idx == static_cast<int>(lnds.size()))
                {
                    lnds.push_back(x);
                }
                else
                {
                    lnds[idx] = x;
                }
            }
            res += list_size - static_cast<int>(lnds.size());
        }
        return res;
    }
};

int main() { return 0; }