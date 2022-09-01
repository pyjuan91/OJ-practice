#include <algorithm>
#include <cstdbool>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool validTicTacToe(vector<string>& board)
    {
        return checkOffensive(board);
    }

    bool checkOffensive(vector<string>& b)
    {
        int Xnum = 0, Onum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == 'X')
                    Xnum++;
                else if (b[i][j] == 'O')
                    Onum++;
            }
        }
        if (Xnum - Onum == 1) {
            return !checkOwin(b);
        } else if (Xnum == Onum) {
            return !checkXwin(b);
        }
        return false;
    }

    bool checkXwin(vector<string>& b)
    {
        return checkDiagnal(b, 'X') || checkHorizontal(b, 'X') || checkVertical(b, 'X');
    }

    bool checkOwin(vector<string>& b)
    {
        return checkDiagnal(b, 'O') || checkHorizontal(b, 'O') || checkVertical(b, 'O');
    }

    bool checkDiagnal(vector<string>& b, char c)
    {
        if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[2][2] == c)
            return true;
        if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[2][0] == c)
            return true;
        return false;
    }

    bool checkHorizontal(vector<string>& b, char c)
    {
        for (int i = 0; i < 3; i++) {
            if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][2] == c)
                return true;
        }
        return false;
    }

    bool checkVertical(vector<string>& b, char c)
    {
        for (int i = 0; i < 3; i++) {
            if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[2][i] == c) {
                return true;
            }
        }
        return false;
    }
};
int main(void) { return 0; }