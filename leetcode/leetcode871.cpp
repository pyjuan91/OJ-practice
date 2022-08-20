#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        // int ans = INT32_MAX, pos = 0, checker = 0, maxFuel = 0, index;
        // for (int i = 0; i < stations.size(); i++) {
        //     if (stations[i][0] > pos && stations[i][0] <= pos + startFuel) {
        //         checker = 1;
        //     }
        // }
        return minVal(target, 0, startFuel, stations);
    }
    int minVal(int target, int pos, int fuel, vector<vector<int>> stations)
    {
        if (pos+fuel >= target)
            return 0;
        int ans = INT32_MAX, checker = 0, mv;
        for (int i = 0; i < stations.size(); i++) {
            if (stations[i][0] > pos && stations[i][0] <= pos + fuel) {
                mv = minVal(target, stations[i][0],
                    fuel + stations[i][1] - stations[i][0] + pos, stations);
                if (mv != -1) {
                    ans = min(ans, mv + 1);
                    checker = 1;
                }
            }
        }
        if (checker == 0)
            return -1;
        return ans;
    }
};
int main(void) { return 0; }