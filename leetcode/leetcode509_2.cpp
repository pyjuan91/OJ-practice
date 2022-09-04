#include <iostream>
using namespace std;
class Solution {
private:
    long long fibo[35] = {};

public:
    int fib(int n)
    {
        fibo[0] = 0, fibo[1] = 1;
        for (int i = 2; i <= n; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        return fibo[n];
    }
};
int main(void) { return 0; }