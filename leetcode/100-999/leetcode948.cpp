#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool getScore(vector<int>& tokens, int& power, int& score, int& left, int& right)
    {
        if (left > right)
            return false;
        power -= tokens[left];
        left++;
        score++;
        return true;
    }
    bool getPower(vector<int>& tokens, int& power, int& score, int& left, int& right)
    {
        if (left > right)
            return false;
        power += tokens[right];
        right--;
        score--;
        return true;
    }
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        if (tokens.size() == 0)
            return 0;
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1, score = 0;
        for (;;) {
            if (left < tokens.size() && power < tokens[left] || right < left)
                break;
            while (left < tokens.size() && power >= tokens[left]
                && getScore(tokens, power, score, left, right)) {
            }
            if (right <= left || score == 0)
                break;
            getPower(tokens, power, score, left, right);
        }
        return score;
    }
};
int main(void)
{
    Solution s;
    vector<int> v = { 100, 200, 300, 400 };
    int power = 200;
    s.bagOfTokensScore(v, power);
    return 0;
}