#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        map<int, int> m;
        for (auto& i : tasks) {
            if (m.count(i) == 0)
                m[i] = 1;
            else
                m[i] += 1;
        }
        int res = 0;
        for (auto i : m) {
            if (i.second == 1)
                return -1;
            res += i.second / 3;
            res += i.second % 3 ? 1 : 0;
        }
        return res;
    }
};
int main(void) { return 0; }