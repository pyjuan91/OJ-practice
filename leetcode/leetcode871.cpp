#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
//     {
//         // int ans = INT32_MAX, pos = 0, checker = 0, maxFuel = 0, index;
//         // for (int i = 0; i < stations.size(); i++) {
//         //     if (stations[i][0] > pos && stations[i][0] <= pos + startFuel) {
//         //         checker = 1;
//         //     }
//         // }
//         return minVal(target, 0, startFuel, stations);
//     }
//     int minVal(int target, int pos, int fuel, vector<vector<int>> stations)
//     {
//         if (pos+fuel >= target)
//             return 0;
//         int ans = INT32_MAX, checker = 0, mv;
//         for (int i = 0; i < stations.size(); i++) {
//             if (stations[i][0] > pos && stations[i][0] <= pos + fuel) {
//                 mv = minVal(target, stations[i][0],
//                     fuel + stations[i][1] - stations[i][0] + pos, stations);
//                 if (mv != -1) {
//                     ans = min(ans, mv + 1);
//                     checker = 1;
//                 }
//             }
//         }
//         if (checker == 0)
//             return -1;
//         return ans;
//     }
// };
struct node {
    int fuel, index;
    bool operator<(const node& b) const
    {
        return fuel < b.fuel;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        priority_queue<node> pq;
        int pos = 0, ans = 0, index;
        while (pos + startFuel < target) {
            for (int i = 0; i < stations.size(); i++) {
                if (stations[i][0] > pos && stations[i][0] <= pos + startFuel) {
                    node n;
                    n.fuel = stations[i][1];
                    n.index = i;
                    stations[i][0] = -1;
                    pq.push(n);
                }
            }
            if (pq.empty())
                return -1;
            ans++;
            index = pq.top().index;
            if (stations[index][0] > pos) {
                startFuel = startFuel - (stations[index][0] - pos) + stations[index][1];
                pos = stations[index][0];
            } else {
                startFuel += stations[index][1];
            }
            cout << "ref " << stations[index][0] << " " << stations[index][1] << endl;
            cout << "pos: " << pos << " fuel: " << startFuel << endl;
            pq.pop();
        }
        return ans;
    }
};
int main(void)
{
    vector<vector<int>> stations;
    stations = { { 25, 27 }, { 36, 187 }, { 140, 186 }, { 378, 6 }, { 492, 202 }, { 517, 89 }, { 579, 234 }, { 673, 86 }, { 808, 53 }, { 954, 49 } };
    Solution s;
    s.minRefuelStops(1000, 83, stations);
    return 0;
}