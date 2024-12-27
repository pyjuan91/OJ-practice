#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    const size_t n = values.size();
    vector<int> plus(n), minus(n);

    for (size_t i = 0; i < n; ++i) {
      plus[i] = values[i] + i;
      minus[i] = values[i] - i;
    }

    int max_plus = plus[0];
    int ans = 0;
    for (size_t i = 1; i < n; ++i) {
      ans = max(ans, max_plus + minus[i]);
      max_plus = max(max_plus, plus[i]);
    }

    return ans;
  }
};

int main() {
  return 0;
}