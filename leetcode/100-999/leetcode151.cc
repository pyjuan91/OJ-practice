#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string str;
        vector<string> v;
        while (ss >> str) {
            v.push_back(str);
        }
        string res = "";
        bool first = true;
        while(!v.empty()) {
            if(first)first = false;
            else res.append(" ");
            res.append(v.back());
            v.pop_back();
        }
        return res;
    }
};
int main(void) { return 0; }