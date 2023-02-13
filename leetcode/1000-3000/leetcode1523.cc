#include <bits/stdc++.h>
using namespace std;
int main() { return 0; };
class Solution {
 public:
  int countOdds(int low, int high) {
    int res = 0;
    if (low % 2 == 0) low++;
    if (high % 2 == 0) high--;
    for (int i = low; i <= high; i += 2) res += 1;
    return res;
  }
};