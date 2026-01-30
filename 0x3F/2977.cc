#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long minimumCost(string source, string target, vector<string>& original,
                        vector<string>& changed, vector<int>& cost) {
    const int n = source.size(), m = original.size();
    unordered_map<string, int> get_hash;
    int hash_idx = 0;
    for (int i = 0; i < m; i++) {
      if (!get_hash.count(original[i])) get_hash[original[i]] = hash_idx++;
      if (!get_hash.count(changed[i])) get_hash[changed[i]] = hash_idx++;
    }
    unordered_map<int, string> get_rev_hash;
    for (const auto& [k, v] : get_hash) {
      get_rev_hash[v] = k;
    }
    const int64_t kInf = (INT64_MAX >> 1);
    vector<vector<int64_t>> g(hash_idx, vector<int64_t>(hash_idx, kInf));
    for (int i = 0; i < hash_idx; i++) g[i][i] = 0;
    for (int i = 0; i < m; i++) {
      int u = get_hash[original[i]], v = get_hash[changed[i]];
      g[u][v] = min(g[u][v], static_cast<int64_t>(cost[i]));
    }

    for (int k = 0; k < hash_idx; k++) {
      for (int u = 0; u < hash_idx; u++) {
        for (int v = 0; v < hash_idx; v++) {
          g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
        }
      }
    }
    unordered_map<string, unordered_map<string, int64_t>> transfer_cost;
    for (int u = 0; u < hash_idx; u++) {
      string u_str = get_rev_hash[u];
      for (int v = 0; v < hash_idx; v++) {
        if (g[u][v] < kInf and u != v) {
          string v_str = get_rev_hash[v];
          transfer_cost[u_str][v_str] = g[u][v];
        }
      }
    }

    set<int> lengths;
    for (const auto& [k, _] : transfer_cost) {
      lengths.insert(k.size());
    }

    vector<int64_t> min_cost(n, -1);
    auto get_min_cost_start_with = [&](this auto&& self,
                                       int start_idx) -> int64_t {
      if (start_idx == n) return 0LL;
      if (min_cost[start_idx] != -1) return min_cost[start_idx];
      int64_t& res = min_cost[start_idx] = kInf;
      if (source[start_idx] == target[start_idx])
        res = min(res, self(start_idx + 1));
      for (const int& len : lengths) {
        if (start_idx + len > n) break;
        string src_str = source.substr(start_idx, len);
        string tar_str = target.substr(start_idx, len);
        if (transfer_cost.count(src_str) and
            transfer_cost[src_str].count(tar_str)) {
          int64_t cur_cost = transfer_cost[src_str][tar_str];
          res = min(res, cur_cost + self(start_idx + len));
        }
      }
      return res;
    };

    int64_t res = get_min_cost_start_with(0);
    return res >= kInf ? -1LL : res;
  }
};

int main() { return 0; }