#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s)
    {
        int vowel = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'a' || s[i] == 'e'
                || s[i] == 'i' || s[i] == 'o'
                || s[i] == 'u' || s[i] == 'A'
                || s[i] == 'E' || s[i] == 'I'
                || s[i] == 'O' || s[i] == 'U') {
                if (i < len / 2)
                    vowel += 1;
                else
                    vowel -= 1;
            }
        }
        if (vowel == 0)
            return true;
        return false;
    }
};
int main(void) { return 0; }