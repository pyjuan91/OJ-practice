#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int res_time = 0;
    for (int i = 0; i <= k; i++) res_time += min(tickets[i], tickets[k]);
    for (int i = k + 1; i < tickets.size(); i++)
      res_time += min(tickets[i], tickets[k] - 1);
    return res_time;
  }
};
int main() { return 0; }