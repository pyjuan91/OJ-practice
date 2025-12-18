#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    static constexpr int kMod = 1e9 + 7;
    using Matrix              = array<array<int, 26>, 26>;
    Matrix get_matrix(const vector<int>& nums)
    {
        Matrix res{};
        for(int i = 0; i < 26; i++)
        {
            for(int j = 1; j <= nums[i]; j++)
            {
                res[(i + j) % 26][i] = 1;
            }
        }
        return res;
    }

    Matrix matrix_multiply(const Matrix& left, const Matrix& right)
    {
        Matrix res{};
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                for(int k = 0; k < 26; k++)
                {
                    res[i][j] = (res[i][j] + (1LL * left[i][k] * right[k][j] % kMod)) % kMod;
                }
            }
        }
        return res;
    }

    Matrix fast_power(Matrix matrix, int expo)
    {
        Matrix res{};
        for(int i = 0; i < 26; i++)
            res[i][i] = 1;
        while(expo)
        {
            if(expo & 1)
            {
                res = matrix_multiply(res, matrix);
            }
            matrix = matrix_multiply(matrix, matrix);
            expo >>= 1;
        }
        return res;
    }

    public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums)
    {
        auto matrix         = get_matrix(nums);
        auto transed_matrix = fast_power(matrix, t);
        array<int, 26> org{};
        for(const auto& c : s)
        {
            org[c - 'a']++;
        }
        int res = 0;
        for(int j = 0; j < 26; j++)
        {
            if(org[j] == 0)
                continue;
            int tot = 0;
            for(int i = 0; i < 26; i++)
            {
                tot = (tot + transed_matrix[i][j]) % kMod;
            }
            res = (res + (1LL * org[j] * tot % kMod)) % kMod;
        }
        return res;
    }
};

int main() { return 0; }