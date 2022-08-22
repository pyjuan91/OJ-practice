#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// class Solution {
// public:
//     vector<int> movesToStamp(string stamp, string target)
//     {
//         stack<int> s;
//         queue<int> top, left, right, bottom;
//         vector<int> ans, complete(target.size());
//         string str;
//         for (int i = 0; i < stamp.size(); i++) {
//             str += "?";
//         }
//         int pos;
//         for (;;) {
//             pos = target.find(stamp);
//             if (pos == -1)
//                 break;
//             top.push(pos);
//             target.replace(pos, stamp.size(), str);
//         }
//         if (top.empty())
//             return ans;
//         for (int i = 0; i < target.size(); i++) {
//             if (target[i] == stamp[0]) {
//                 left.push(i);
//                 for (int j = 0; j < stamp.size(); j++) {
//                     if (i + j >= target.size()) {
//                         return ans;
//                     }
//                     if (target[i + j] == '?' || target[i + j] == stamp[j]) {
//                         target[i + j] = '?';
//                         continue;
//                     }
//                     if (target[i + j] == stamp[0]) {
//                         i = i + j - 1;
//                         break;
//                     }
//                     return ans;
//                 }
//             }
//         }
//         for (int i = target.size() - 1; i >= 0; i--) {
//             if (target[i] == stamp[stamp.size() - 1]) {
//                 right.push(i - stamp.size() + 1);
//                 for (int j = 0; j < stamp.size(); j++) {
//                     if (i - j <= 0) {
//                         return ans;
//                     }
//                     if (target[i - j] == '?' || target[i - j] == stamp[stamp.size() - 1 - j]) {
//                         target[i - j] = '?';
//                         continue;
//                     }
//                     if (target[i - j] == stamp[stamp.size() - 1]) {
//                         i = i - j + 1;
//                         break;
//                     }
//                     return ans;
//                 }
//             }
//         }
//         for (int i = 0; i < target.size(); i++) {
//             if (target[i] != '?') {
//                 for (int j = 0; j < stamp.size(); j++) {
//                     if (target[i] == stamp[j]) {
//                         bottom.push(i - j);
//                         for (int k = j; k < stamp.size(); k++) {
//                             if (i + k >= target.size())
//                                 return ans;
//                             if (target[i + k] == '?' || target[i + k] == stamp[k]) {
//                                 target[i + k] = '?';
//                                 continue;
//                             }
//                             return ans;
//                         }
//                     }
//                 }
//             }
//         }
//         while (!bottom.empty()) {
//             ans.push_back(bottom.front());
//             bottom.pop();
//         }
//         while (!left.empty()) {
//             ans.push_back(left.front());
//             left.pop();
//         }
//         while (!right.empty()) {
//             ans.push_back(right.front());
//             right.pop();
//         }
//         while (!top.empty()) {
//             ans.push_back(top.front());
//             top.pop();
//         }
//         return ans;
//     }
// };
class Solution {
public:
    bool match(string a, string b)
    {
        if (a.length() != b.length())
            return false;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i] && a[i] != '?' && b[i] != '?')
                return false;
        }
        return true;
    }
    bool allChange(string s)
    {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '?')
                return false;
        }
        return true;
    }
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> ans;
        int lenStamp = stamp.length(), lenTarget = target.length();
        string repStr = "";
        for (int i = 0; i < lenStamp; i++) {
            repStr += "?";
        }
        bool checker = true;
        while (checker) {
            checker = false;
            for (int i = 0; i < lenTarget - lenStamp + 1; i++) {
                string b = target.substr(i, lenStamp);
                if (!allChange(b) && match(stamp, b)) {
                    checker = true;
                    ans.push_back(i);
                    target.replace(i, lenStamp, repStr);
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if (allChange(target))
            return ans;
        return vector<int>(0);
    }
};
int main(void)
{
    Solution s;
    s.movesToStamp("abca", "aabcaca");
    return 0;
}