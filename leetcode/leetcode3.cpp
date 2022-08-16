#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int hashTable[128], len[50005], ans;
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0 || s.length() == 1) {
            return s.length();
        }
        for (int i = 0; i < 128; i++) {
            hashTable[i] = -1;
        }
        hashTable[s[0]] = 0, len[0] = 1, ans = 1;
        for (int i = 1; i < s.length(); i++) {
            if (hashTable[s[i]] != -1) {
                for (int j = 0; j < 128; j++) {
                    if (hashTable[j] != -1 && hashTable[j] < hashTable[s[i]]) {
                        hashTable[j] = -1;
                    }
                }
                len[i] = i - hashTable[s[i]];
                hashTable[s[i]] = i;
            } else {
                hashTable[s[i]] = i;
                len[i] = len[i - 1] + 1;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            ans = max(ans, len[i]);
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}