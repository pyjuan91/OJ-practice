#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        vector<char> res;
        for (int i = 0; i < 205; i++) {
            char c;
            if (i >= strs[0].length())
                return string(res.begin(), res.end());
            else
                c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return string(res.begin(), res.end());
                }
            }
            res.push_back(c);
        }
        return string(res.begin(), res.end());
    }
};
int main(void) { return 0; }