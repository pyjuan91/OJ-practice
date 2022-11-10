#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    set<int> s;
    for (auto i : nums) {
      if (s.count(i))
        return true;
      s.insert(i);
    }
    return false;
  }
};
int main(void) { return 0; }