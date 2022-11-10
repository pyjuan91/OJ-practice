#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// class entry {
// public:
//     int index, value;

//     entry(int index, int value)
//     {
//         this->index = index;
//         this->value = value;
//     }

//     bool operator<(const entry& b) const
//     {
//         return value < b.value;
//     }
//     bool operator>=(const entry& b) const
//     {
//         return !(*this < b);
//     }
// };
// bool myGreater(entry& a, entry& b)
// {
//     return a >= b;
// }
// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& properties)
//     {
//         int n = properties.size();
//         vector<entry> attack, defense;
//         vector<int> used(n);
//         for (int i = 0; i < n; i++) {
//             entry e1(i, properties[i][0]);
//             entry e2(i, properties[i][1]);
//             attack.push_back(e1);
//             defense.push_back(e2);
//         }
//         sort(attack.begin(), attack.end(), myGreater);
//         sort(defense.begin(), defense.end(), myGreater);
//         // for (entry& i : attack) {
//         //     cout << i.index << " " << i.value << endl;
//         // }
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (used[attack[i].index] == 1)
//                 continue;
//             used[attack[i].index] = 1;
//             unordered_set<int> us;
//             for (int k = i + 1; k < n; k++)
//                 if (attack[k].value < attack[i].value)
//                     us.insert(attack[k].index);
//             for (int j = 0; j < n; j++) {
//                 if (defense[j].index != attack[i].index)
//                     continue;
//                 else {
//                     for (int k = j + 1; k < n; k++) {
//                         if (used[defense[k].index]==1)
//                             continue;
//                         if (us.find(defense[k].index) != us.end()
//                             && defense[k].value < defense[j].value) {
//                             ans++;
//                             used[defense[k].index] = 1;
//                         }
//                     }
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };
bool myCompare(vector<int>& a, vector<int>& b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        int maxDefense = INT_MIN, ans = 0, att = INT_MIN;
        sort(properties.begin(), properties.end(), myCompare);
        for (int i = 0; i < properties.size(); i++) {
            if (properties[i][1] < maxDefense) {
                ans++;
                continue;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        return ans;
    }
};
int main(void)
{
    Solution s;
    vector<vector<int>> v = { { 7, 9 }, { 10, 7 }, { 6, 9 }, { 10, 4 }, { 7, 5 }, { 7, 10 } };
    cout << s.numberOfWeakCharacters(v) << endl;
    return 0;
}