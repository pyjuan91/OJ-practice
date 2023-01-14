#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string parse = countAndSay(n - 1);
        vector<string> res;
        for (int i = 0; i < parse.length(); i++) {
            int j = i + 1;
            for (j; j < parse.length() && parse[j] == parse[i]; j++)
                ;
            res.push_back(to_string(j - i) + string(1, parse[i]));
            i = j - 1;
        }
        string ans = "";
        for (auto i : res)
            ans.append(i);
        return ans;
    }
};
int main(void) { return 0; }