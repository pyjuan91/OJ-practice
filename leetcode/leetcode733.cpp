#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        draw(image, sr, sc, image[sr][sc], image.size(), image[0].size());
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[0].size(); j++) {
                // cout << checker[i][j] << " ";
                if (image[i][j] == -1) {
                    image[i][j] = color;
                }
            }
        }
        return image;
    }
    void draw(vector<vector<int>>& checker, int sr, int sc, int rec, int m, int n)
    {
        checker[sr][sc] = -1;
        if (sr + 1 < m && checker[sr + 1][sc] == rec) {
            draw(checker, sr + 1, sc, rec, m, n);
        }
        if (sr - 1 >= 0 && checker[sr - 1][sc] == rec) {
            draw(checker, sr - 1, sc, rec, m, n);
        }
        if (sc + 1 < n && checker[sr][sc + 1] == rec) {
            draw(checker, sr, sc + 1, rec, m, n);
        }
        if (sc - 1 >= 0 && checker[sr][sc - 1] == rec) {
            draw(checker, sr, sc - 1, rec, m, n);
        }
    }
};
int main(void)
{
    vector<vector<int>> image;
    vector<int> entry;
    entry.push_back(1);
    entry.push_back(1);
    entry.push_back(1);
    image.push_back(entry);
    entry.clear();
    entry.push_back(1);
    entry.push_back(1);
    entry.push_back(0);
    image.push_back(entry);
    entry.clear();
    entry.push_back(1);
    entry.push_back(0);
    entry.push_back(1);
    image.push_back(entry);
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[0].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    Solution s;
    s.floodFill(image, 1, 1, 2);
    return 0;
}