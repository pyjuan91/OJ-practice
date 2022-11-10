#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        int zeroNum = 0;
        vector<int> res;
        multiset<int, greater<int>> ms;
        multiset<int, greater<int>>::iterator iter, f;
        if (changed.size() % 2)
            return vector<int>();
        for (int& i : changed) {
            if (i)
                ms.insert(i);
            else
                zeroNum++;
        }
        if (zeroNum % 2)
            return vector<int>();
        zeroNum /= 2;
        while (zeroNum--)
            res.push_back(0);
        iter = ms.begin();
        for (;;) {
            if (iter == ms.end())
                break;
            f = ms.find(*iter / 2);
            if (*iter % 2 == 1 || f == ms.end()) {
                return vector<int>();
            }
            res.push_back(*iter / 2);
            ms.erase(f);
            iter++;
        }
        return res;
    }
};
int main(void)
{
    vector<int> changed = { 1, 3, 4, 2, 6, 8 };
    Solution s;
    changed = s.findOriginalArray(changed);
    for (int& i : changed) {
        cout << i << endl;
    }
    return 0;
}