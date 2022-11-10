#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int mai = values[0], res = INT_MIN;
        for (int i = 1; i < values.size(); i++) {
            res = max(res, values[i] - i + mai);
            mai = max(mai, values[i] + i);
        }
        return res;
    }
};
int main(void) { return 0; }