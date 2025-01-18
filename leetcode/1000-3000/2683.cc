#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    // test a[0] == 0;
    bool test1 = true, test2 = true;
    int prv = 0;
    for (int i = 0; i < n; i++) {
      prv = prv ^ derived[i];
    }
    test1 = (prv == 0);
    // test a[0] == 1;
    prv = 1;
    for (int i = 0; i < n; i++) {
      prv = prv ^ derived[i];
    }
    test2 = (prv == 1);

    return test1 or test2;
  }
};

int main() {
  return 0;
}