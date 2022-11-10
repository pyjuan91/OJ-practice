#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    int head, tail;
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++) {
      head = tail = nums[i];
      while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
        tail = nums[++i];
      }
      string str;
      if (tail == head)
        str = to_string(tail);
      else
        str = to_string(head) + "->" + to_string(tail);
      ans.push_back(str);
    }
    return ans;
  }
};
int main(void) {
  vector<int> v1 = {0, 1, 2, 4, 5, 7};
  vector<int> v2 = {0, 2, 3, 4, 6, 8, 9};
  Solution s;
  vector<string> ans = s.summaryRanges(v1);
  for (auto i : ans) {
    cout << i << endl;
  }
  cout << endl;
  ans = s.summaryRanges(v2);
  for (auto i : ans) {
    cout << i << endl;
  }
  return 0;
}