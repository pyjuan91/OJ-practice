#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int mod = numRows * 2 - 2;
        string str = "";
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.length(); j += mod) {
                    str += s[j];
                }
            } else {
                int complement = mod - i - i;
                for (int j = i; j < s.length(); j += mod) {
                    str += s[j];
                    if (j + complement < s.length())
                        str += s[j + complement];
                }
            }
        }
        return str;
    }
};
int main(void)
{
    Solution s;
    string str;
    int numrows;
    cin >> str;
    cin >> numrows;
    cout << s.convert(str, numrows);
    return 0;
}