#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    const int kMax = 1e6 + 5;
    vector buses_in_stops(kMax, vector<int>());
    vector<int> dist(kMax, -1);

    for (int i = 0; i < routes.size(); i++) {
      for (const auto& stop : routes[i]) {
        buses_in_stops[stop].push_back(i);
      }
    }

    deque<int> q = {source};
    dist[source] = 0;
    unordered_set<int> visisted_bus;

    while (!q.empty()) {
      auto cur_stop = q.front();
      q.pop_front();

      for (const auto& bus_id : buses_in_stops[cur_stop]) {
        if (!visisted_bus.count(bus_id)) {
          visisted_bus.insert(bus_id);
          for (const auto& nxt_stop : routes[bus_id]) {
            if (dist[nxt_stop] == -1) {
              dist[nxt_stop] = dist[cur_stop] + 1;
              q.push_back(nxt_stop);
            }
          }
        }
      }
    }

    return dist[target];
  }
};

int main() { return 0; }