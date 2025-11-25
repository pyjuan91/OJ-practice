#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id,
                                          int level)
    {
        int n = watchedVideos.size();
        unordered_map<string, int> cnt_videos;
        queue<pair<int, int>> q;
        vector<bool> vis(n);
        q.push({id, 0});
        vis[id] = true;
        while(!q.empty())
        {
            auto [u, d] = q.front();
            q.pop();
            if(d == level)
            {
                for(const auto& video : watchedVideos[u])
                {
                    cnt_videos[video]++;
                }
                continue;
            }
            for(const auto& v : friends[u])
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push({v, d + 1});
                }
            }
        }
        vector<string> vids;
        for(const auto [vid, cnt] : cnt_videos)
        {
            vids.push_back(vid);
        }
        sort(vids.begin(), vids.end(), [&](const auto& a, const auto& b) {
            if(cnt_videos[a] == cnt_videos[b])
                return a < b;
            return cnt_videos[a] < cnt_videos[b];
        });

        return vids;
    }
};

int main() { return 0; }
