#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> um;
        um[1] = "I";
        um[5] = "V";
        um[10] = "X";
        um[50] = "L";
        um[100] = "C";
        um[500] = "D";
        um[1000] = "M";
        string str = "";
        while (num >= 1000) {
            str += um[1000];
            num -= 1000;
        }
        if (num >= 900) {
            str += um[100] + um[1000];
            num -= 900;
        }
        if (num >= 500) {
            str += um[500];
            num -= 500;
        }
        if (num >= 400) {
            str += um[100] + um[500];
            num -= 400;
        }
        while (num >= 100) {
            str += um[100];
            num -= 100;
        }
        if (num >= 90) {
            str += um[10] + um[100];
            num -= 90;
        }
        if (num >= 50) {
            str += um[50];
            num -= 50;
        }
        if (num >= 40) {
            str += um[10] + um[40];
            num -= 40;
        }
        while (num >= 10) {
            str += um[10];
            num -= 10;
        }
        if (num >= 9) {
            str += um[1] + um[10];
            num -= 9;
        }
        if (num >= 5) {
            str += um[5];
            num -= 5;
        }
        if (num >= 4) {
            str += um[1] + um[5];
            num -= 4;
        }
        while (num >= 1) {
            str += um[1];
            num -= 1;
        }
        return str;
    }
};
int main(void) { return 0; }