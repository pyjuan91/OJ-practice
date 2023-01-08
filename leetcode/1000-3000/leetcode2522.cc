#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPartition(string s, int k)
    {
        long long res = 0, num = 0, len = s.length(), cur = 0;
        while (cur < len) {
            while (cur < len && num <= k) {
                if (num * 10 + (s[cur] - '0') <= k) {
                    num = num * 10 + (s[cur] - '0');
                    cur += 1;
                } else {
                    res += 1;
                    break;
                }
            }
            if (num == 0)
                return -1;
            else if (cur == len && num)
                res += 1;
            else
                num = 0;
        }
        return (int)res;
    }
};
int main(void) { return 0; }