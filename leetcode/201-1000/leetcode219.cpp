#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    set<int> s;
    int sz = nums.size();
    vector<int> lookupList;
    for (auto i : nums) {
      if (s.count(i))
        lookupList.push_back(i);
      else
        s.insert(i);
    }
    for (auto i : lookupList) {
      int gap = sz, mingap = k + 1;
      for (auto j : nums) {
        if (j == i) {
          mingap = min(mingap, gap);
          gap = 0;
        } else if (gap != sz) {
          gap++;
        }
      }
      if (mingap < k)
        return true;
    }
    return false;
  }
};
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> s;

    if (k <= 0)
      return false;
    if (k >= nums.size())
      k = nums.size() - 1;

    for (int i = 0; i < nums.size(); i++) {
      if (i > k)
        s.erase(nums[i - k - 1]);
      if (s.find(nums[i]) != s.end())
        return true;
      s.insert(nums[i]);
    }

    return false;
  }
};
int main(void) { return 0; }