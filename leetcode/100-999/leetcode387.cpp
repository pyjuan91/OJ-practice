#include <iostream>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s)
    {
        int ht[26] = {};
        for (auto i : s)
            ht[i - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (ht[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
int main(void)
{
    return 0;
}