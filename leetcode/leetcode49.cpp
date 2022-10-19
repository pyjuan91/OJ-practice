#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> uom;
        for (string& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            uom[sorted].push_back(str);
        }
        for (auto i : uom) {
            res.push_back(i.second);
        }
        return res;
    }
};
int main(void)
{
    return 0;
}