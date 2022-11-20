#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees)
    {
        vector<vector<int>> d, u;
        set<vector<int>> stored;
        if (trees.empty())
            return vector<vector<int>>();
        sort(trees.begin(), trees.end());
        map<int, vector<int>> m;
        for (auto i : trees) {
            m[i[0]].push_back(i[1]);
        }

        auto iter = m.end();
        iter--;
        int left = m.begin()->first;
        int right = iter->first;

        for (auto i : m) {
            if (i.first == left) {
                d.push_back({ i.first, i.second.front() });
                u.push_back({ i.first, i.second.back() });
            } else {
                if (d.size() == 1) {
                    d.push_back({ i.first, i.second.front() });
                } else {
                    while (d.size() > 1) {
                        pair<int, int> l = { d.back()[0], d.back()[1] };
                        d.pop_back();
                        pair<int, int> ll = { d.back()[0], d.back()[1] };
                        // cout << "now down: " << i.first << " " << i.second.front() << endl;
                        // cout << "last: " << l.first << " " << l.second << endl;
                        // cout << "llast: " << ll.first << " " << ll.second << endl;
                        // cout << endl;
                        int nx = i.first - l.first;
                        int ny = i.second.front() - l.second;
                        int ox = l.first - ll.first;
                        int oy = l.second - ll.second;

                        if (ny * ox >= nx * oy) {
                            d.push_back({ l.first, l.second });
                            break;
                        }
                    }
                    d.push_back({ i.first, i.second.front() });
                }

                if (u.size() == 1) {
                    u.push_back({ i.first, i.second.back() });
                } else {
                    while (u.size() > 1) {
                        pair<int, int> l = { u.back()[0], u.back()[1] };
                        u.pop_back();
                        pair<int, int> ll = { u.back()[0], u.back()[1] };
                        // cout << "now up: " << i.first << " " << i.second.back() << endl;
                        // cout << "last: " << l.first << " " << l.second << endl;
                        // cout << "llast: " << ll.first << " " << ll.second << endl;
                        // cout << endl;
                        int nx = i.first - l.first;
                        int ny = i.second.back() - l.second;
                        int ox = l.first - ll.first;
                        int oy = l.second - ll.second;

                        if (ny * ox <= nx * oy) {
                            u.push_back({ l.first, l.second });
                            break;
                        }
                    }
                    u.push_back({ i.first, i.second.back() });
                }
            }
        }

        for (auto i : d) {
            // cout << i[0] << " " << i[1] << endl;
            stored.insert({ i[0], i[1] });
        }
        // cout << endl;
        for (auto i : u) {
            // cout << i[0] << " " << i[1] << endl;
            stored.insert({ i[0], i[1] });
        }

        for (auto i : m[left])
            stored.insert({ left, i });
        for (auto i : m[right])
            stored.insert({ right, i });

        return vector<vector<int>>(stored.begin(), stored.end());
    }
};
int main(void)
{
    Solution s;
    vector<vector<int>> trees = { { 2, 2 }, { 1, 1 }, { 2, 4 }, { 2, 0 }, { 4, 2 }, { 3, 3 } };
    s.outerTrees(trees);
    return 0;
}