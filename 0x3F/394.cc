#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    size_t i = 0;
    return parse(s, i);
  }

 private:
  string parse(const string& s, size_t& i) {
    string res;
    while (i < s.size() and s[i] != ']') {
      if (isdigit(static_cast<unsigned char>(s[i]))) {
        int num = 0;
        while (i < s.size() and isdigit(static_cast<unsigned char>(s[i]))) {
          num = num * 10 + (s[i++] - '0');
        }
        i++;
        string child = parse(s, i);
        i++;
        while (num--) res += child;
      } else {
        res.push_back(s[i++]);
      }
    }
    return res;
  }
};

int main() { return 0; }