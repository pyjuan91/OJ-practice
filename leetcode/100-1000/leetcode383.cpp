#include <iostream>
using namespace std;
class Solution {
private:
    int map[26];

public:
    bool canConstruct(string ransomNote, string magazine)
    {
        for (int i = 0; i < 26; i++)
            map[i] = 0;
        for (int i = 0; i < magazine.length(); i++) {
            map[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if (map[ransomNote[i] - 'a'] == 0)
                return false;
            map[ransomNote[i] - 'a']--;
        }
        return true;
    }
};
int main(void) { return 0; }