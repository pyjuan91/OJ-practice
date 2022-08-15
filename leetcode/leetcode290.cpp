#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> um;
        unordered_map<string, char> umverse;
        int index = 0;
        stringstream ss;
        ss << s;
        string str;
        while (ss >> str) {
            if (index >= pattern.length())
                return false;
            if (um.find(pattern[index]) != um.end() && um[pattern[index]] != str
                || umverse.find(str) != umverse.end() && umverse[str] != pattern[index])
                return false;
            um[pattern[index]] = str;
            umverse[str] = pattern[index++];
            str.clear();
        }
        if (index != pattern.length())
            return false;
        return true;
    }
};
int main(void)
{
    return 0;
}