#include <bits/stdc++.h>
#include "debug.cc"

using namespace std;

class Solution {
public:
  double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1,
    vector<vector<string>>& pairs2, vector<double>& rates2) {
    unordered_map<string, int> currency_index;
    int n = 0;
    auto addCurrency = [&](const string& s) {
      if (currency_index.find(s) == currency_index.end()) {
        currency_index[s] = n++;
      }
      };
    for (auto& p : pairs1) {
      addCurrency(p[0]), addCurrency(p[1]);
    }
    for (auto& p : pairs2) {
      addCurrency(p[0]), addCurrency(p[1]);
    }
    int start = currency_index[initialCurrency];
    vector<vector<pair<int, long double>>> graph1(n);
    for (int i = 0; i < pairs1.size(); i++) {
      int u = currency_index[pairs1[i][0]];
      int v = currency_index[pairs1[i][1]];
      long double rate = rates1[i];
      graph1[u].push_back({ v, rate });
      graph1[v].push_back({ u, static_cast<long double>(1) / rate });
    }

    vector<long double> dp1(n, 0.0);
    dp1[start] = 1.0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto& edge : graph1[u]) {
        int v = edge.first;
        long double rate = edge.second;
        if (dp1[v] < dp1[u] * rate) {
          dp1[v] = dp1[u] * rate;
          q.push(v);
        }
      }
    }

    vector<vector<pair<int, long double>>> graph2(n);
    for (int i = 0; i < pairs2.size(); i++) {
      int u = currency_index[pairs2[i][0]];
      int v = currency_index[pairs2[i][1]];
      long double rate = rates2[i];
      graph2[u].push_back({ v, rate });
      graph2[v].push_back({ u, static_cast<long double>(1) / rate });
    }

    vector<long double> dp2(n, 0.0);
    dp2[start] = 1.0;
    q.push(start);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto& edge : graph2[u]) {
        int v = edge.first;
        long double rate = edge.second;
        if (dp2[v] < dp2[u] * rate) {
          dp2[v] = dp2[u] * rate;
          q.push(v);
        }
      }
    }

    long double ans = dp1[start];
    for (int x = 0; x < n; x++) {
      if (dp1[x] > static_cast<long double>(0) && dp2[x] > static_cast<long double>(0)) {
        long double candidate = dp1[x] * (static_cast<long double>(1) / dp2[x]);
        ans = max(ans, candidate);
      }
    }
    return static_cast<double>(ans);
  }
};


int main() {
  Solution s;
  string initialCurrency = "USD";
  vector<vector<string>> pairs1 = { {"USD", "JPY"}, {"JPY", "CNY"}, {"CNY", "USD"} };
  vector<double> rates1 = { 1.0, 0.1, 10.0 };
  vector<vector<string>> pairs2 = { {"USD", "JPY"}, {"JPY", "CNY"}, {"CNY", "USD"} };
  vector<double> rates2 = { 1.0, 0.1, 10.0 };
  cout << s.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2) << endl;
  return 0;
}