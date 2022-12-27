#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumBags(vector<int>& capacity,
        vector<int>& rocks, int additionalRocks)
    {
        int n = capacity.size(), res = 0;
        for (int i = 0; i < n; i++) {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for (int i = 0; i < n; i++) {
            if (capacity[i] == 0) {
                res++;
                continue;
            }
            if (additionalRocks < capacity[i])
                break;
            res++;
            additionalRocks -= capacity[i];
        }
        return res;
    }
};
int main(void)
{
    return 0;
}