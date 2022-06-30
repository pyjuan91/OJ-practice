#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber) {
            ans += _chart[columnNumber % 26];
            if (columnNumber % 26 == 0) {
                columnNumber /= 26;
                columnNumber -= 1;
            } else {
                columnNumber /= 26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    string _chart[26] = {
        "Z", "A", "B", "C", "D", "E", "F",
        "G", "H", "I", "J", "K", "L", "M",
        "N", "O", "P", "Q", "R", "S", "T",
        "U", "V", "W", "X", "Y"
    };
};
int main(void)
{
    Solution s;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(28) << endl;
    cout << s.convertToTitle(52) << endl;
    cout << s.convertToTitle(701) << endl;
    return 0;
}