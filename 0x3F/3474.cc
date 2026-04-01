#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string generateString(string str1, string str2) {
    const int n = str1.size(), m = str2.size();
    string res(n + m - 1, ' ');
    for (int i = n - 1; i >= 0; i--) {
      if (str1[i] == 'T') {
        bool ok = true;
        for (int j = i; j < i + m; j++) {
          if (not(res[j] == str2[j - i]) and not(res[j] == ' ')) {
            ok = false;
            break;
          }
          res[j] = str2[j - i];
        }
        if (not ok) return "";
      }
    }
    vector<bool> has_sat(n, false);
    vector<int> last_chance(n, -1);
    for (int i = 0; i < n; i++) {
      if (str1[i] == 'F') {
        for (int j = i; j < i + m; j++) {
          if (res[j] != ' ' and res[j] != str2[j - i]) has_sat[i] = true;
          if (res[j] == ' ') last_chance[i] = j;
        }
        if (not has_sat[i] and last_chance[i] == -1) return "";
      }
    }

    for (int i = 0; i < n; i++) {
      if (str1[i] == 'F') {
        for (int j = i; j < i + m; j++) {
          if (res[j] == ' ') {
            res[j] = 'a';
          }
          if (res[j] != str2[j - i]) has_sat[i] = true;
        }
        if (!has_sat[i]) {
          res[last_chance[i]] = 'b';
        }
      }
    }

    return res;
  }
};

int main() { return 0; }