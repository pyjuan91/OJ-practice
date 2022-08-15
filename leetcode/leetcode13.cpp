#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<char, int> m;

public:
    int romanToInt(string s)
    {
        init();
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && m[s[i + 1]] > m[s[i]]) {
                ans += m[s[i + 1]] - m[s[i]];
                i++;
            } else {
                ans += m[s[i]];
            }
        }
        return ans;
    }
    void init()
    {
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
    }
};
int main(void)
{
    return 0;
}