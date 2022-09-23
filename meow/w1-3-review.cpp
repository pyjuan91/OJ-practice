#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> rec1, rec2;
int cnt = 0;
void helper(int n, int a, int b, int c)
{
    if (n == 1) {
        rec1.push_back(a);
        rec2.push_back(c);
        cnt++;
        return;
    }
    helper(n - 1, a, c, b);
    rec1.push_back(a);
    rec2.push_back(c);
    cnt++;
    helper(n - 1, b, a, c);
}
int main(void)
{
    int n;
    cin >> n;
    helper(n, 1, 2, 3);
    printf("%d\n", cnt);
    for (int i = 0; i < rec1.size(); i++) {
        printf("%d %d\n", rec1[i], rec2[i]);
    }
    return 0;
}