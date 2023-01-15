#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> intervalIntersection(
            vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
            int ll = firstList.size(), rl = secondList.size();
            int li = 0, ri = 0;
            vector<vector<int>> res;
            while (li < ll && ri < rl) {
                if (secondList[ri][1] < firstList[li][0])
                    ri += 1;
                else if (firstList[li][1] < secondList[ri][0])
                    li += 1;
                else {
                    res.push_back({max(firstList[li][0], secondList[ri][0]),
                                   min(firstList[li][1], secondList[ri][1])});
                    if (firstList[li][1] > secondList[ri][1])
                        ri += 1;
                    else
                        li += 1;
                }
            }
            return res;
        }
};
int main(void) { return 0; }