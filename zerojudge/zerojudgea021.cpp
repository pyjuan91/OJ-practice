#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BigInteger {
private:
    static const int BASE = 10000;
    static const int WIDTH = 4;
    vector<int> s;

public:
    BigInteger operator=(long long num)
    {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num);
        return *this;
    }
    BigInteger operator=(const string str)
    {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const BigInteger& x)
    {
        out << x.s.back();
        for (int i = x.s.size() - 2; i >= 0; i--) {
            char buf[20];
            sprintf(buf, "%04d", x.s[i]);
            for (int j = 0; j < strlen(buf); j++) {
                out << buf[j];
            }
        }
        return out;
    }
    friend istream& operator>>(istream& in, BigInteger& x)
    {
        string s;
        in >> s;
        x = s;
        return in;
    }
    bool operator<(const BigInteger& b) const
    {
        if (s.size() != b.s.size()) {
            return s.size() < b.s.size();
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != b.s[i])
                return s[i] < b.s[i];
        }
        return false;
    }
    bool operator>=(const BigInteger& b) const
    {
        return !(*this < b);
    }
    BigInteger operator+(const BigInteger& b) const
    {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = g;
            if (i < s.size())
                x += s[i];
            if (i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator-(const BigInteger& b) const
    {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++) {
            if (g == 0 && i >= b.s.size() && i >= s.size()) {
                break;
            }
            int x = g;
            g = 0;
            if (i < s.size())
                x += s[i];
            if (i < b.s.size()) {
                if (s[i] >= b.s[i]) {
                    x -= b.s[i];
                } else {
                    x += BASE - b.s[i];
                    g = -1;
                }
            }
            c.s.push_back(x);
        }
        for (int i = c.s.size() - 1; i > 0; i--) {
            if (c.s[i] != 0)
                break;
            c.s.pop_back();
        }
        return c;
    }
    BigInteger operator*(const BigInteger& b) const
    {
        BigInteger c;
        c.s.clear();
        c.s.resize(s.size() + b.s.size());
        for (int i = 0, g = 0; i < s.size(); i++) {
            for (int j = 0; j < b.s.size() || g != 0; j++) {
                int x = g;
                x += c.s[i + j];
                if (j < b.s.size())
                    x += s[i] * b.s[j];
                c.s[i + j] = x % BASE;
                g = x / BASE;
            }
        }
        for (int i = c.s.size() - 1; i > 0; i--) {
            if (c.s[i] != 0)
                break;
            c.s.pop_back();
        }
        return c;
    }
    BigInteger operator/(const BigInteger& b) const
    {
        BigInteger divi;
        divi = *this;
        BigInteger c;
        c = 0;
        BigInteger ONE;
        ONE = 1;
        BigInteger basey;
        basey = 10000;
        BigInteger tmp;
        c.s.clear();
        // tmp.s.push_back(divi.s[0]);
        // cout << tmp << endl;
        // cout << divi << endl;
        // cout << s.size() << endl;
        // cout << b.s.size() << endl;
        for (int i = s.size() - 1; i >= (int)b.s.size() - 1; i--) {
            tmp.s.clear();
            for (int j = i - (int)b.s.size() + 1; j <= i; j++) {
                if (j < (int)divi.s.size())
                    tmp.s.push_back(divi.s[j]);
            }
            if (tmp < b)
                c = i != (int)b.s.size() - 1 ? c * basey : c;
            else {
                int k;
                for (k = 1; k < BASE; k++) {
                    BigInteger K;
                    K = k;
                    K = b * K;
                    if (tmp < K)
                        break;
                }
                BigInteger K;
                K = k - 1;
                c = c + K;
                c = i != (int)b.s.size() - 1 ? c * basey : c;
                tmp = b * (K);
                // cout << "tmp: " << tmp << endl;
                for (int j = i - (int)b.s.size(); j >= 0; j--) {
                    tmp = tmp * basey;
                }
                divi = divi - tmp;
            }
        }
        // c = c / basey;
        return c;
    }
};
int main(void)
{
    BigInteger a, b;
    char op;
    cin >> a >> op >> b;
    switch (op) {
    case '+':
        cout << a + b << endl;
        break;
    case '-':
        if (a >= b)
            cout << a - b << endl;
        else
            cout << "-" << b - a << endl;
        break;
    case '*':
        cout << a * b << endl;
        break;
    default:
        if (a >= b)
            cout << a / b << endl;
        else
            cout << 0 << endl;
        break;
    }
    return 0;
}