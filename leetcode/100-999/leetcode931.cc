#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), res = INT32_MAX;
        if (n == 1)
            return matrix[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n - 1; j++) {
                matrix[i][j]
                    += min({ matrix[i - 1][j - 1],
                        matrix[i - 1][j],
                        matrix[i - 1][j + 1] });
            }
            matrix[i][0] += min(matrix[i - 1][0], matrix[i - 1][1]);
            matrix[i][n - 1] += min(matrix[i - 1][n - 1], matrix[i - 1][n - 2]);
        }
        for (int j = 0; j < n; j++) {
            res = min(res, matrix[n - 1][j]);
        }
        return res;
    }
};
int main(void) { return 0; }