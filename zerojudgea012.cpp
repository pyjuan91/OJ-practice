#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int getNumber(string s) {
    int v = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i != s.length() - 1 && m[s[i]] < m[s[i + 1]]) {
            v = v + m[s[i + 1]] - m[s[i]];
            i++;
        } else {
            v += m[s[i]];
        }
    }
    return v;
}
string getString(int ans) {
    if (ans == 0)
        return "ZERO";
    string v;
    while (ans >= 1000) {
        v += "M";
        ans -= 1000;
    }
    while (ans >= 900) {
        v += "CM";
        ans -= 900;
    }
    while (ans >= 500) {
        v += "D";
        ans -= 500;
    }
    while (ans >= 400) {
        v += "CD";
        ans -= 400;
    }
    while (ans >= 100) {
        v += "C";
        ans -= 100;
    }
    while (ans >= 90) {
        v += "XC";
        ans -= 90;
    }
    while (ans >= 50) {
        v += "L";
        ans -= 50;
    }
    while (ans >= 40) {
        v += "XL";
        ans -= 40;
    }
    while (ans >= 10) {
        v += "X";
        ans -= 10;
    }
    while (ans >= 9) {
        v += "IX";
        ans -= 9;
    }
    while (ans >= 5) {
        v += "V";
        ans -= 5;
    }
    while (ans >= 4) {
        v += "IV";
        ans -= 4;
    }
    while (ans >= 1) {
        v += "I";
        ans -= 1;
    }
    return v;
}
int main(void) {
    // initialize map
    m.insert(pair<char, int>('I', 1));
    m.insert(pair<char, int>('V', 5));
    m.insert(pair<char, int>('X', 10));
    m.insert(pair<char, int>('L', 50));
    m.insert(pair<char, int>('C', 100));
    m.insert(pair<char, int>('D', 500));
    m.insert(pair<char, int>('M', 1000));

    string str1, str2;
    while (cin >> str1 && str1 != "#") {
        cin >> str2;
        int num1 = getNumber(str1);
        int num2 = getNumber(str2);
        int ans = abs(num1 - num2);
        cout << getString(ans) << endl;
    }
    return 0;
}