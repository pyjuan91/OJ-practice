#include <bits/stdc++.h>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);
class Solution {
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) == -1) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (guess(right) == 0)
            return right;
        else
            return left;
    }
};
int main(void) { return 0; }