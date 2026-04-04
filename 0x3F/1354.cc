#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPossible(vector<int>& target) {
    priority_queue<int64_t> pq(target.begin(), target.end());
    int64_t sum = accumulate(target.begin(), target.end(), 0LL);
    while (!pq.empty()) {
      int64_t cur = pq.top();
      pq.pop();
      int64_t rest = sum - cur;
      if (cur == 1 or rest == 1) return true;
      if (rest == 0 or cur <= rest or cur % rest == 0) return false;
      cur %= rest;
      sum = rest + cur;
      pq.push(cur);
    }
    return true;
  }
};

int main() { return 0; }