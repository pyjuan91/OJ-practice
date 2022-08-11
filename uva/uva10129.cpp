#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int head[26], tail[26], hp, G[26][26];
void cl()
{
    hp = -1;
    for (int i = 0; i < 26; i++) {
        head[i] = tail[i] = 0;
        for (int j = 0; j < 26; j++) {
            G[i][j] = 0;
        }
    }
}
void euler(int u)
{
    for (int v = 0; v < 26; v++) {
        if (G[u][v]) {
            G[u][v] -= 1;
            euler(v);
        }
    }
}
bool checkEmpty()
{
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (G[i][j])
                return false;
        }
    }
    return true;
}
bool checkAndFindHead()
{
    int oddNumHead = 0, oddNumTail = 0;
    for (int i = 0; i < 26; i++) {
        if (head[i] == tail[i])
            continue;
        else if (head[i] - 1 == tail[i]) {
            oddNumHead++;
            hp = i;
        } else if (head[i] + 1 == tail[i]) {
            oddNumTail++;
        } else
            return false;
    }
    return oddNumHead + oddNumTail == 0 || (oddNumHead == 1 && oddNumTail == 1);
}
int main(void)
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cl();
        string s;
        while (n--) {
            cin >> s;
            // if (s[0] != s[s.length() - 1]) {
            head[s[0] - 'a'] += 1;
            tail[s[s.length() - 1] - 'a'] += 1;
            G[s[0] - 'a'][s[s.length() - 1] - 'a'] += 1;
            // }
        }
        if (checkAndFindHead()) {
            if (hp == -1) {
                for (int i = 0; i < 26; i++) {
                    if (head[i]) {
                        hp = i;
                        break;
                    }
                }
            }
            euler(hp);
            if (checkEmpty()) {
                cout << "Ordering is possible." << endl;
            } else {
                cout << "The door cannot be opened." << endl;
            }
        } else {
            cout << "The door cannot be opened." << endl;
        }
    }
    return 0;
}