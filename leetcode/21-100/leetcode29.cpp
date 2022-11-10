#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        long ans = 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long longDividend = labs(dividend);
        long longDivisor = labs(divisor);
        bool isNegative = dividend < 0 ^ divisor < 0;
        while (longDividend >= longDivisor) {
            long divTmp = longDivisor, power = 1;
            while (divTmp << 1 <= longDividend) {
                divTmp = divTmp << 1;
                power = power << 1;
            }
            ans += power;
            longDividend -= divTmp;
        }
        return isNegative ? -ans : ans;
    }
};
int main(void)
{
    Solution s;
    cout << s.divide(-2147483638, -1) << endl;
    return 0;
}