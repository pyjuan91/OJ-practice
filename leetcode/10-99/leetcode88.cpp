#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> ans;
    int f1 = 0, f2 = 0;
    while (f1 < m) {
      while (f2 < n && nums2[f2] < nums1[f1]) {
        ans.push_back(nums2[f2++]);
      }
      ans.push_back(nums1[f1++]);
    }
    while (f2 < n)
      ans.push_back(nums2[f2++]);
    nums1 = ans;
  }
};
int main(void) {}