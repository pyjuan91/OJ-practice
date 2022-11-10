#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0, lens = s.length(), lent = t.length();
        for (i = 0; i < lens; i++) {
            bool flag = false;
            for (j; j < lent; j++) {
                if (t[j] == s[i]) {
                    flag = true;
                    j++;
                    break;
                }
            }
            if (!flag)
                return false;
        }
        return true;
    }
};
int main(void)
{
    string s = "abc";
    string t = "ahbgdc";
    Solution so;
    cout << so.isSubsequence(s, t) << endl;
    return 0;
}