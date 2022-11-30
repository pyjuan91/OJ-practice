#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num)
    {
        for (int i = 0; (long long)i * i <= (long long)num; i++) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};
int main(void)
{
    return 0;
}