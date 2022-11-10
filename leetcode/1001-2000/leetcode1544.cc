#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string makeGood(string s)
    {
        vector<char> v;
        for (int i = 0; i < s.length(); i++) {
            if (!v.empty()) {
                char c = v.back();
                if (c >= 'a' && c <= 'z') {
                    if (c - 'a' == s[i] - 'A')
                        v.pop_back();
                    else {
                        v.push_back(s[i]);
                    }
                } else {
                    if (c - 'A' == s[i] - 'a')
                        v.pop_back();
                    else {
                        v.push_back(s[i]);
                    }
                }
            } else {
                v.push_back(s[i]);
            }
        }
        string res(v.begin(), v.end());
        return res;
    }
};
int main(void) { return 0; }