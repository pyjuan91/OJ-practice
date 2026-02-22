#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    const array<int, 4> kHours = {8, 4, 2, 1};
    const array<int, 6> kMinutes = {32, 16, 8, 4, 2, 1};
    vector<string> res;
    auto patty = [&](int hours_cnt, int minutes_cnt) -> void {

    };
    for (int i = 0; i <= turnedOn; i++) {
      patty(i, turnedOn - i);
    }
    return res;
  }
};

int main() { return 0; }