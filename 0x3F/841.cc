#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n);

        auto dfs = [&](this auto& self, int u) -> void {
            vis[u] = true;
            for (const auto& room : rooms[u])
            {
                if (!vis[room])
                    self(room);
            }
        };
        dfs(0);

        return all_of(vis.begin(), vis.end(), [](auto x) { return x; });
    }
};

int main()
{
    return 0;
}