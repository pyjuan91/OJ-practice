#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string solve(string& str) {
            vector<char> res;
            for (auto i : str) {
                if (i == '#') {
                    if (res.size()) res.pop_back();
                    continue;
                }
                res.emplace_back(i);
            }
            return {res.begin(), res.end()};
        }
        bool backspaceCompare(string s, string t) {
            s = solve(s), t = solve(t);
            return s == t;
        }
};
int main(void) { return 0; }