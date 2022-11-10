#include <iostream>
#include <cstdbool>
#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string p = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                p += s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                p += s[i] - 'A' + 'a';
            else if(s[i] >= '0' && s[i] <= '9')
                p += s[i];
        }
        for (int i = 0; i < p.length() / 2; i++)
            if (p[i] != p[p.length() - 1 - i])
                return false;
        return true;
    }
};
int main(void)
{
    string s = "0P";
    Solution solu;
    cout<<solu.isPalindrome(s);
    return 0;
}