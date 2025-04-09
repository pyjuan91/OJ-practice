#include <bits/stdc++.h>
using namespace std;

const int64_t kMax = 1e5 + 5;
const int64_t kMod = 1e9 + 7;
array<int64_t, kMax> dp79, dp_others;
int init = []() {
  dp79[0] = dp_others[0] = 1;
  dp79[1] = dp_others[1] = 1;
  dp79[2] = dp_others[2] = 2;
  dp79[3] = dp_others[3] = 4;
  for (int i = 4; i < kMax; i++) {
    dp79[i] = (dp79[i - 1] + dp79[i - 2] + dp79[i - 3] + dp79[i - 4]) % kMod;
    dp_others[i] = (dp_others[i - 1] + dp_others[i - 2] + dp_others[i - 3]) % kMod;
  }
  return 0;
  } ();

class Solution {
public:
  int countTexts(string pressedKeys) {
    int n = pressedKeys.size();
    int64_t res = 1, cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt++;
      if (i == n - 1 or pressedKeys[i] != pressedKeys[i + 1]) {
        if (pressedKeys[i] == '7' or pressedKeys[i] == '9') {
          res = (res * dp79[cnt]) % kMod;
        }
        else {
          res = (res * dp_others[cnt]) % kMod;
        }
        cnt = 0;
      }
    }
    return static_cast<int>(res);
  }
};

int main() { return 0; }