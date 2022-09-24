#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int main(void)
{
    int a, b, A[3], B[3], ans = 0;
    scanf("%d%d", &a, &b);
    switch (a) {
    case 0:
        A[0] = A[1] = A[2] = 0;
        break;
    case 1:
        A[0] = 1;
        A[1] = A[2] = 0;
        break;
    case 2:
        A[0] = A[2] = 0;
        A[1] = 1;
        break;
    case 3:
        A[0] = A[1] = 1;
        A[2] = 0;
        break;
    case 4:
        A[0] = A[1] = 0;
        A[2] = 1;
        break;
    case 5:
        A[0] = A[2] = 1;
        A[1] = 0;
        break;
    case 6:
        A[0] = 0;
        A[1] = A[2] = 1;
        break;
    case 7:
        A[0] = A[1] = A[2] = 1;
        break;
    default:
        break;
    }
    switch (b) {
    case 0:
        B[0] = B[1] = B[2] = 0;
        break;
    case 1:
        B[0] = 1;
        B[1] = B[2] = 0;
        break;
    case 2:
        B[0] = B[2] = 0;
        B[1] = 1;
        break;
    case 3:
        B[0] = B[1] = 1;
        B[2] = 0;
        break;
    case 4:
        B[0] = B[1] = 0;
        B[2] = 1;
        break;
    case 5:
        B[0] = B[2] = 1;
        B[1] = 0;
        break;
    case 6:
        B[0] = 0;
        B[1] = B[2] = 1;
        break;
    case 7:
        B[0] = B[1] = B[2] = 1;
        break;
    default:
        break;
    }
    if (A[0] || B[0])
        ans += 1;
    if (A[1] || B[1])
        ans += 2;
    if (A[2] || B[2])
        ans += 4;
    printf("%d\n", ans);
    return 0;
}