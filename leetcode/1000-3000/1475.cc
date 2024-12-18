#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> res;
    for (int i = 0; i < prices.size(); i++) {
      int discount = 0;
      for (int j = i + 1; j < prices.size(); j++) {
        if (prices[j] <= prices[i]) {
          discount = prices[j];
          break;
        }
      }
      res.push_back(prices[i] - discount);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> prices = { 8,4,6,2,3 };
  vector<int> res = s.finalPrices(prices);
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}