#include <iostream>
using namespace std;
class Solution {
public:
    int head, maxLen;
    string longestPalindrome(string s)
    {
        head = maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            findFromMid(s, i, i);
            findFromMid(s, i, i + 1);
        }
        return s.substr(head, maxLen);
    }
    void findFromMid(string s, int left, int right)
    {
        while (left >= 0 && right < s.length()
            && s[left] == s[right]) {
            left--, right++;
        }
        if (right - left - 1 > maxLen) {
            maxLen = right - left - 1;
            head = left + 1;
        }
        return;
    }
};
int main(void)
{
    return 0;
}