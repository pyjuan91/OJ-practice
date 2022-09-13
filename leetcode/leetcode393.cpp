#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool validUtf8(vector<int>& data)
    {
        int n = data.size(), cur;
        vector<string> v(n);
        string str;

        for (int i = 0; i < n; i++) {
            str = "00000000";
            cur = 7;
            while (data[i]) {
                str[cur] = (data[i] % 2) + '0';
                cur--;
                data[i] /= 2;
            }
            // cout << str << endl;
            v[i] = str;
        }

        for (int i = 0; i < n; i++) {
            if (v[i][0] == '0')
                continue;
            else if (v[i][0] == '1' && v[i][1] == '0')
                return false;
            else if (v[i][0] == '1' && v[i][1] == '1' && v[i][2] == '0') {
                if (i + 1 < n && v[i + 1][0] == '1' && v[i + 1][1] == '0')
                    i++;
                else
                    return false;
            } else if (v[i][0] == '1' && v[i][1] == '1' && v[i][2] == '1' && v[i][3] == '0') {
                if (i + 1 < n && i + 2 < n && v[i + 1][0] == '1'
                    && v[i + 1][1] == '0' && v[i + 2][0] == '1' && v[i + 2][1] == '0')
                    i += 2;
                else
                    return false;
            } else if (v[i][0] == '1' && v[i][1] == '1' && v[i][2] == '1'
                && v[i][3] == '1' && v[i][4] == '0') {
                if (i + 1 < n && i + 2 < n && i + 3 < n && v[i + 1][0] == '1'
                    && v[i + 1][1] == '0' && v[i + 2][0] == '1' && v[i + 2][1] == '0'
                    && v[i + 3][0] == '1' && v[i + 3][1] == '0')
                    i += 3;
                else
                    return false;
            } else
                return false;
        }
        return true;
    }
};
int main(void)
{
    Solution s;
    vector<int> data = { 197, 130, 1 };
    s.validUtf8(data);
    return 0;
}