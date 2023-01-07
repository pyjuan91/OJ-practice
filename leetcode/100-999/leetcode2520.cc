#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDigits(int num)
    {
        int res = 0, val = num, cur;
        while (val) {
            cur = val % 10;
            res += (num % cur == 0);
            val /= 10;
        }
        return res;
    }
};
int main(void) { return 0; }