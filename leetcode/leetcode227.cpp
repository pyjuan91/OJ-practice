#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
private:
    stack<long long> num;
    stack<char> oper;

public:
    int calculate(string s)
    {
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                long long ln = 0;
                int power = 0;
                while (i < s.length() && isdigit(s[i])) {
                    ln *= 10;
                    ln += s[i] - '0';
                    i++;
                }
                // cout << ln << endl;
                if (!oper.empty() && oper.top() == '*') {
                    ln *= num.top();
                    oper.pop();
                    num.pop();
                } else if (!oper.empty() && oper.top() == '/') {
                    ln = num.top() / ln;
                    oper.pop();
                    num.pop();
                }
                // cout << ln << endl;
                num.push(ln);
                i--;
            } else if (s[i] == ' ') {
                continue;
            } else {
                oper.push(s[i]);
            }
        }

        reverse();

        long long a, b;
        while (num.size() > 1) {
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            if (oper.top() == '+') {
                a += b;
            } else {
                a -= b;
            }
            oper.pop();
            num.push(a);
        }
        return (int)num.top();
    }

    void reverse()
    {
        stack<long long> bufferNum;
        while (!num.empty()) {
            bufferNum.push(num.top());
            num.pop();
        }
        swap(num, bufferNum);

        stack<char> bufferOper;
        while (!oper.empty()) {
            bufferOper.push(oper.top());
            oper.pop();
        }
        swap(oper, bufferOper);
    }
};
int main(void)
{
    Solution s;
    string str = "14/3*2";
    cout << s.calculate(str) << endl;
    return 0;
}