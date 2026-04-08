#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
 private:
  unordered_map<int, int> _cnt;
  vector<int> _nums1, _nums2;

 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    _nums1 = nums1, _nums2 = nums2;
    for (const auto& num : _nums2) _cnt[num]++;
  }

  void add(int index, int val) {
    _cnt[_nums2[index]]--;
    if (_cnt[_nums2[index]] == 0) _cnt.erase(_nums2[index]);
    _nums2[index] += val;
    _cnt[_nums2[index]]++;
  }

  int count(int tot) {
    int res = 0;
    for (const auto& num1 : _nums1) {
      if (_cnt.count(tot - num1)) res += _cnt[tot - num1];
    }
    return res;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main() { return 0; }