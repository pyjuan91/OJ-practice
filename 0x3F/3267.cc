#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  unordered_map<int, int> cnt;
  void add_variant(int num) {
    deque<char> digits;
    while (num) {
      digits.push_front((char)('0' + num % 10));
      num /= 10;
    }
    while (digits.size() < 7) digits.push_front('0');

    string str_dig(digits.begin(), digits.end());
    unordered_set<int> var;
    for (int i = 0; i < 7; i++) {
      for (int j = i + 1; j < 7; j++) {
        swap(str_dig[i], str_dig[j]);
        var.insert(stoi(str_dig));
        for (int k = 0; k < 7; k++) {
          for (int w = k + 1; w < 7; w++) {
            swap(str_dig[k], str_dig[w]);
            var.insert(stoi(str_dig));
            swap(str_dig[k], str_dig[w]);
          }
        }
        swap(str_dig[i], str_dig[j]);
      }
    }
    for (const auto& x : var) cnt[x]++;
  }

 public:
  int countPairs(vector<int>& nums) {
    int res = 0;
    for (const auto& num : nums) {
      if (cnt.count(num)) res += cnt[num];
      add_variant(num);
    }
    return res;
  }
};

int main() { return 0; }