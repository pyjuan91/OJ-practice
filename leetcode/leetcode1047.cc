#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s)
    {
        vector<char> v;
        for (char& c : s) {
            if (!v.empty() && v.back() == c)
                v.pop_back();
            else
                v.push_back(c);
        }
        string res(v.begin(), v.end());
        return res;
    }
};
int main(void)
{
    return 0;
}