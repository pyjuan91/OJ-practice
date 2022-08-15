#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num)
    {
        while (digits(num) != 1) {
        }
        return num;
    }
    int digits(int& num)
    {
        int d = 0, sum = 0;
        if (num == 0)
            return 1;
        while (num) {
            d++;
            sum += num % 10;
            num /= 10;
        }
        num = sum;
        return d;
    }
};
int main(void)
{
    return 0;
}