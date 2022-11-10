#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;
        for (int i = 0; i < columnTitle.length(); i++) {
            ans *= 26;
            ans += columnTitle[i] - 'A' + 1;
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}