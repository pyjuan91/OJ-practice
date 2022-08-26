#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     bool reorderedPowerOf2(int n)
//     {
//         string nToString = to_string(n);
//         sort(nToString.begin(), nToString.end());
//         for (int i = 0; i < 31; i++) {
//             string compare = to_string(1 << i);
//             sort(compare.begin(), compare.end());
//             if (nToString == compare)
//                 return true;
//         }
//         return false;
//     }
// };
class Solution {
private:
    long long Tzuyu(int n)
    {
        long long ret = 0;
        while (n) {
            ret += pow(10, n % 10);
            n /= 10;
        }
        return ret;
    }

public:
    bool reorderedPowerOf2(int n)
    {
        long long iu = Tzuyu(n);
        for (int i = 0; i < 31; i++) {
            if (Tzuyu(1 << i) == iu)
                return true;
        }
        return false;
    }
};
int main(void) { return 0; }