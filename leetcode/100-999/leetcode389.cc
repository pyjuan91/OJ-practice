#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t)
    {
        int rec[26] = {};
        for (int i = 0; i < s.length(); i++) {
            rec[s[i] - 'a'] -= 1;
            rec[t[i] - 'a'] += 1;
        }
        rec[t[t.length() - 1] - 'a'] += 1;
        for (int i = 0; i < 26; i++) {
            if (rec[i] != 0)
                return (char)('a' + i);
        }
        return ' ';
    }
};
int main(void) { return 0; }