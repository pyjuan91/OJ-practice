#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        IUisMyWife(ans, "", n, n);
        return ans;
    }
    void IUisMyWife(vector<string>& v, string str, int left, int right)
    {
        if (left == 0 && right == 0) {
            v.push_back(str);
            return;
        }
        if (left > 0)
            IUisMyWife(v, str + "(", left - 1, right);
        if (right > left)
            IUisMyWife(v, str + ")", left, right - 1);
    }
};
int main(void)
{
    return 0;
}