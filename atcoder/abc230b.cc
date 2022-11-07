#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
    string str;
    stack<char> st;
    cin >> str;
    int start, end, len = str.length(), i = 0, xn = 0;
    while (i < len) {
        if (str[i] == 'o')
            break;
        else {
            xn++;
            if (xn > 2) {
                printf("No\n");
                return 0;
            }
        }
        i++;
    }
    while (i < len) {
        if (str[i] == 'o') {
            start = i;
            if (i + 1 < len && str[i + 1] != 'x') {
                printf("No\n");
                return 0;
            }
            if (i + 2 < len && str[i + 2] != 'x') {
                printf("No\n");
                return 0;
            }
            i += 3;
        } else {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}