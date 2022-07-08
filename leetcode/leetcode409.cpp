#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s)
    {
        map<char, int> m;
        for (auto i : s) {
            m[i] += 1;
        }
        int ans = 0, flag = 0;
        for (auto i : m) {
            ans += i.second / 2;
            if (i.second % 2 == 1)
                flag = 1;
        }
        return ans * 2 + flag;
    }
};
int main(void)
{
    return 0;
}