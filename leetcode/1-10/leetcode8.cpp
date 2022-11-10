#include <cstdint>
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string s)
    {
        int neg = 0, start = 0, ans = 0, over = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && !start)
                continue;
            if (s[i] == '+' && i + 1 < s.length() && s[i + 1] >= '0' && s[i + 1] <= '9' && !start)
                continue;
            if (s[i] == '-' && i + 1 < s.length() && s[i + 1] >= '0' && s[i + 1] <= '9' && !start) {
                neg = 1;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                start = 1;
                uint64_t checker = ans;
                checker *= 10;
                checker += s[i] - '0';
                if (checker <= INT32_MAX) {
                    ans *= 10;
                    ans += s[i] - '0';
                } else {
                    over = 1;
                    break;
                }
            } else
                break;
        }
        if (over == 1)
            return neg == 0 ? INT32_MAX : INT32_MIN;
        return neg == 0 ? ans : -ans;
    }
};
int main(void)
{
    return 0;
}