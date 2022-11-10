#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x)
    {
        int upperLimit = (pow(2, 31) - 1) / 10;
        int lowerLimit = -(pow(2, 31) / 10);
        int ans = 0;
        while (x) {
            int lastDigit = x % 10;
            if (ans <= upperLimit && ans >= lowerLimit) {
                int temp = ans * 10 + lastDigit;
                ans = temp;
                x /= 10;
            } else {
                return 0;
            }
        }
        return ans;
    }
};
int main(void) { return 0; }