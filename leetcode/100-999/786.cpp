#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    double left = 0.0, right = 1.0;

    while (left < right) {
      double mid = (left + right) / 2.0;
      int smaller_factions_count = 0;
      int numerator = 1, denominator = 1;

      for (int j = 1, i = 0; j < arr.size(); j++) {
        while (i < arr.size() - 1 && i < j && (double)arr[i] < mid * arr[j]) {
          i++;
        }
        smaller_factions_count += i;
        if (i >= arr.size() - 1) {
          break;
        }
        // cout << "i: " << i << " j: " << j << " smaller_factions_count: " << smaller_factions_count << endl;
        if (numerator * arr[j] > denominator * arr[i]) {
          numerator = arr[i];
          denominator = arr[j];
        }
      }

      if (smaller_factions_count == k - 1) {
        return {numerator, denominator};
      } else if (smaller_factions_count < k - 1) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return {};
  }
};
int main() {
  Solution s;
  vector<int> arr = {1, 2, 3, 5};
  int k = 3;
  vector<int> ans = s.kthSmallestPrimeFraction(arr, k);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}