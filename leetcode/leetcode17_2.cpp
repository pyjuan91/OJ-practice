#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
    unordered_map<int, vector<char>> m;

public:
    vector<string> letterCombinations(string digits)
    {
        vector<char> v;
        v = { 'a', 'b', 'c' }, m[2] = v;
        v = { 'd', 'e', 'f' }, m[3] = v;
        v = { 'g', 'h', 'i' }, m[4] = v;
        v = { 'j', 'k', 'l' }, m[5] = v;
        v = { 'm', 'n', 'o' }, m[6] = v;
        v = { 'p', 'q', 'r', 's' }, m[7] = v;
        v = { 't', 'u', 'v' }, m[8] = v;
        v = { 'w', 'x', 'y', 'z' }, m[9] = v;
        vector<string> ans;
        go(digits, ans);
        return ans;
    }
    void go(string digits, vector<string>& v)
    {
        if (digits.length() == 0)
            return;
        vector<string> neo;
        if (v.empty()) {
            for (char& i : m[digits[0] - '0']) {
                string str;
                str = i;
                neo.push_back(str);
            }
        } else {
            for (string& i : v) {
                for (char& j : m[digits[0] - '0']) {
                    string str = i + j;
                    neo.push_back(str);
                }
            }
        }
        v = neo;
        go(digits.substr(1, digits.length() - 1), v);
        return;
    }
};
int main(void)
{
    Solution s;
    vector<string> v = s.letterCombinations("");
    for (auto i : v)
        cout << i << endl;
    return 0;
}