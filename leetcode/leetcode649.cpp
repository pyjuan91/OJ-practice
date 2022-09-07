#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    queue<char> q;
    int n, Rb, Db, Rv, Dv;

public:
    string predictPartyVictory(string senate)
    {
        n = senate.length();
        Rv = Dv = 0;
        for (int i = 0; i < n; i++) {
            q.push(senate[i]);
            if (senate[i] == 'R')
                Rv++;
            else
                Dv++;
        }
        Rb = Db = 0;
        while (q.size() > 1 && Rv && Dv) {
            if (q.front() == 'R') {
                if (Db) {
                    Db--;
                    Rv--;
                } else {
                    Rb++;
                    q.push('R');
                }
            } else {
                if (Rb) {
                    Rb--;
                    Dv--;
                } else {
                    Db++;
                    q.push('B');
                }
            }
            q.pop();
        }
        return q.front() == 'R' ? "Radiant" : "Dire";
    }
};
int main(void) { return 0; }