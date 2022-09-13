#include <bits/stdc++.h>
std::string str;
int n;
void dfs(int left, int right, int cur)
{
    if (left == 0 && right == 0) {
        std::cout << str.substr(0, 2 * n) << "\n";
        return;
    }
    if (left) {
        str[cur] = '(';
        dfs(left - 1, right, cur + 1);
    }
    if (right && right > left) {
        str[cur] = ')';
        dfs(left, right - 1, cur + 1);
    }
}
int main(void)
{
    while (std::cin >> n) {
        str = std::string(2 * n, ' ');
        dfs(n, n, 0);
    }
    return 0;
}