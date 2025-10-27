#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        vector<bool> vis(n);

        auto dfs = [&](this auto& self, int u) -> bool {
            vis[u] = true;
            if (arr[u] == 0)
                return true;

            int right = u + arr[u];
            int left = u - arr[u];
            if (right < n and !vis[right] and self(right))
                return true;
            if (left >= 0 and !vis[left] and self(left))
                return true;
            return false;
        };

        return dfs(start);
    }
};

int main() { return 0; }