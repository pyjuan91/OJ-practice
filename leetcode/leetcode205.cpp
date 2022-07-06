#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> m;
        int len = s.length();
        if (t.length() != len)
            return false;
        for (int i = 0; i < len; i++) {
            if (!m[s[i]]) {
                m[s[i]] = t[i];
            } else if (m[s[i]] != t[i]) {
                return false;
            }
        }
        m.clear();
        for (int i = 0; i < len; i++) {
            if (!m[t[i]]) {
                m[t[i]] = s[i];
            } else if (m[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
int main(void)
{
    return 0;
}