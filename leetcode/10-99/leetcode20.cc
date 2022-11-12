#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s)
    {
        vector<char> v;
        for (char& c : s) {
            if (c == ')') {
                if (!v.empty() && v.back() == '(') {
                    v.pop_back();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (!v.empty() && v.back() == '[') {
                    v.pop_back();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (!v.empty() && v.back() == '{') {
                    v.pop_back();
                } else {
                    return false;
                }
            } else {
                v.push_back(c);
            }
        }

        return v.empty();
    }
};
int main(void) { return 0; }