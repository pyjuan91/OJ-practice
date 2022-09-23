#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BigInteger {
    friend ostream& operator<<(ostream& output, const BigInteger& b);

private:
    const int SIZE = 8;
    const long long MOD = 100000000;
    vector<int> num;
    int digits;

public:
    BigInteger()
    {
        num.clear();
        digits = 0;
    }

    BigInteger(const string& s)
    {
        int e = 0, d;
        digits = 0;
        for (int i = 0; i < s.length() / SIZE; i++) {
            e = 0;
            for (int j = s.length() - (SIZE * (i + 1)); j < s.length() - (SIZE * i); j++) {
                e *= 10;
                e += s[j] - '0';
            }
            num.push_back(e);
            digits += SIZE;
        }
        e = 0;
        d = 0;
        for (int i = 0; i < s.length() % SIZE; i++) {
            e *= 10;
            e += s[i] - '0';
            d++;
        }
        if (d) {
            num.push_back(e);
            digits += d;
        }
        reverse(num.begin(), num.end());
    }

    BigInteger& operator=(const BigInteger& b)
    {
        this->digits = b.digits;
        this->num = b.num;
    }

    int getDigits(void)
    {
        return this->digits;
    }

    bool operator==(const BigInteger& b) const
    {
        if (digits != b.digits)
            return false;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != b.num[i])
                return false;
        }
        return true;
    }

    BigInteger& operator*(const BigInteger& b)
    {
        BigInteger res("0");
        for (int i = b.num.size() - 1; i >= 0; i--) {
            for (int j = num.size() - 1; j >= 0; j--) {
                long long pro = (long long)b.num[i] * (long long)num[j];
                long long carry = pro / MOD;
                carry += (pro%MOD) + res.num[j];
            }
        }
    }
};
ostream& operator<<(ostream& output, const BigInteger& b)
{
    string str;
    for (int i = 0; i < b.num.size(); i++) {
        str = to_string(b.num[i]);
        output << str;
    }
    return output;
}
int main(void)
{
    BigInteger b("12312345678");
    cout << b << endl;

    return 0;
}