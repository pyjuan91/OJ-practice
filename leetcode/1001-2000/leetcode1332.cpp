#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  int removePalindromeSub(string s) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != s[s.length() - 1 - i])
        return 2;
    }
    return 1;
  }
};
int main(void) {
  string s1 = "abb";
  string s2 = "baabb";
  string s3 = "ababa";
  string s4 = "bbaabaaa";
  Solution s;
  cout << s.removePalindromeSub(s1) << endl;
  cout << s.removePalindromeSub(s2) << endl;
  cout << s.removePalindromeSub(s3) << endl;
  cout << s.removePalindromeSub(s4) << endl;
  return 0;
}