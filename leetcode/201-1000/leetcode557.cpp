#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s)
    {
        bool first = true;
        string res, str;
        stringstream ss(s);
        while (ss >> str) {
            reverse(str.begin(), str.end());
            if (first)
                first = false;
            else
                res += " ";
            res += str;
            str.clear();
        }
        return res;
    }
};
int main(void) { return 0; }