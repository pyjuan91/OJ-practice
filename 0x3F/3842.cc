#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> toggleLightBulbs(vector<int>& bulbs) {
    bitset<200> b;
    for (const auto& bulb : bulbs) {
      b.flip(bulb);
    }
    vector<int> res;
    for (int i = 0; i < 200; i++) {
      if (b[i]) res.push_back(i);
    }
    return res;
  }
};

int main() {
  return 0;
}