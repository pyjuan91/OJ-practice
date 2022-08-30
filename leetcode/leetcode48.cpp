#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), start, i;
        start = 0;
        while (start < n / 2) {
            vector<int> tmp(n - 1 - start);
            for (i = start; i < n - 1 - start; i++) {
                tmp[i - start] = matrix[start][i];
            }
            for (i = start; i < n - 1 - start; i++) {
                matrix[start][i] = matrix[n - 1 - i][start];
            }
            for (i = n - 1 - start; i > start; i--) {
                matrix[i][start] = matrix[n - 1 - start][i];
            }
            for (i = n - 1 - start; i > start; i--) {
                matrix[n - 1 - start][i] = matrix[n - 1 - i][n - 1 - start];
            }

            for (i = start; i < n - 1 - start; i++) {
                matrix[i][n - 1 - start] = tmp[i - start];
            }
            start += 1;
        }
    }
};
int main(void) { return 0; }