#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    const int n = s.size();
    vector<bool> reachable(n);
    reachable[0] = true;

    int sliding_windows = 0;
    for (int i = 1; i < n; i++) {
      if (i - minJump >= 0) sliding_windows += (reachable[i - minJump]);
      reachable[i] = (sliding_windows > 0) && (s[i] == '0');
      if (i - maxJump >= 0) sliding_windows -= (reachable[i - maxJump]);
    }

    return reachable.back();
  }
};

int main() { return 0; }