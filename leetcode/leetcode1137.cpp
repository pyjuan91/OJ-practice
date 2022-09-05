#include <iostream>
using namespace std;
class Solution {
private:
    long long tribo[40];

public:
    int tribonacci(int n)
    {
        tribo[0] = 0, tribo[1] = 1, tribo[2] = 1;
        for (int i = 3; i <= n; i++)
            tribo[i] = tribo[i - 1] + tribo[i - 2] + tribo[i - 3];
        return tribo[n];
    }
};

int main(void) { return 0; }