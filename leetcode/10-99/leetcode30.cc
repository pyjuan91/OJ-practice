#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        int sz = words.size(), len = words[0].length();
        for (int i = 0; i < s.length() - len * sz + 1; i++) {
            vector<string> cmp;
            for (int j = i; j < i + sz * len; j += len) {
                cmp.push_back(s.substr(j, len));
            }
            if (is_permutation(words.begin(), words.end(), cmp.begin())) {
                res.push_back(i);
            }
        }
        return res;
    }
};
int main(void)
{
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = { "foo", "bar", "yo" };
    sort(words.begin(), words.end());
    sol.findSubstring(s, words);
    return 0;
}