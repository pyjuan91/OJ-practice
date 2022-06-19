#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    vector<int> v;
    int zn = 0;
    for (auto i : nums) {
      if (i == 0)
        zn++;
      else
        v.push_back(i);
    }
    for (int i = 0; i < zn; i++)
      v.push_back(0);
    nums = v;
  }
};
int main(void) { return 0; }