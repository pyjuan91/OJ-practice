#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s)
    {
        reverse(s.begin(), s.end());
    }
};
int main(void)
{
    return 0;
}
