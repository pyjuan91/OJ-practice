#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> cnt_a(n+1, 0), cnt_b(n+1, 0);
        vector<int> res;
        for (int i=0; i<n; i++) {
          cnt_a[A[i]]++;
          cnt_b[B[i]]++;
          int common = 0;
          for (int j=1; j<=n; j++) {
            common += min(cnt_a[j], cnt_b[j]);
          }
          res.push_back(common);
        }
        return res;
    }
};

int main() {
  return 0;
}