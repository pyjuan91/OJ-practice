#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> str_bank(bank.begin(), bank.end());
    unordered_set<string> vis = {startGene};
    array<char, 4> str_set = {'A', 'C', 'G', 'T'};
    queue<pair<string, int>> q;
    q.push(make_pair(startGene, 0));
    while (!q.empty()) {
      auto [cur_str, cur_step] = q.front();
      q.pop();
      if (cur_str == endGene) return cur_step;
      for (auto& c : cur_str) {
        char org_c = c;
        for (auto rep_c : str_set) {
          if (rep_c != org_c) {
            c = rep_c;
            if (str_bank.count(cur_str) and !vis.count(cur_str)) {
              q.push(make_pair(cur_str, cur_step + 1));
              vis.insert(cur_str);
            }
          }
        }
        c = org_c;
      }
    }
    return -1;
  }
};

int main() { return 0; }