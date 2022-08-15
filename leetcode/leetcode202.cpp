#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool isHappy(int n)
    {
        int tmp;
        set<int> s;
        s.insert(n);
        while (n != 1) {
            tmp = 0;
            while (n) {
                tmp += pow((n % 10), 2);
                n /= 10;
            }
            if (s.count(tmp))
                return false;
            else
                s.insert(tmp);
            n = tmp;
        }
        return true;
    }
};
int main(void)
{
    return 0;
}