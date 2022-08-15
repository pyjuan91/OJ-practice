#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int ht[26] = {};
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++) {
            ht[s[i] - 'a']++;
            ht[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (ht[i] != 0)
                return false;
        }
        return true;
    }
};
int main(void)
{
    return 0;
}