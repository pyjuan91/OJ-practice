#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        int low, mid, high;
        low = 1, high = n;
        while (low <= high) {
            mid = (int)((double)low / 2.0 + (double)high / 2.0);
            if (isBadVersion(mid) && !isBadVersion(mid - 1)) {
                return mid;
            } else if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return mid;
    }
};
int main(void)
{
    return 0;
}