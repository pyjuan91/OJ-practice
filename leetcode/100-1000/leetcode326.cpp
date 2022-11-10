#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
            return false;
        while (n > 1) {
            if (n % 3)
                return false;
            n /= 3;
        }
        return n == 1;
    }
};
int main(void)
{
    return 0;
}