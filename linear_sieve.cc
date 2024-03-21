#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e7 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

void init() {
  for (int i = 2; i <= kMax; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) {
        break;
      }
    }
  }
}