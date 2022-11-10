#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        map<char, int> mp, rec;
        vector<int> ans;
        int lenS = s.length(), lenP = p.length(), len = 0;
        for (auto i : p) {
            mp[i]++;
        }
        for (int i = 0; i < lenS; i++) {
            if (mp[s[i]] && rec[s[i]] < mp[s[i]]) {
                rec[s[i]]++;
                len++;
                if (len == lenP) {
                    ans.push_back(i - len + 1);
                    rec[s[i - len + 1]]--;
                    len--;
                }
            } else if (mp[s[i]] == 0) {
                len = 0;
                rec.clear();
            } else {
                for (int j = i - len; j < i; j++) {
                    if (s[j] == s[i]) {
                        break;
                    } else {
                        rec[s[j]]--;
                        len--;
                    }
                }
            }
        }
        return ans;
    }
};
int main(void)
{
    Solution s;
    string p = "bdgcjwj";
    s.findAnagrams(p, p);
    return 0;
}