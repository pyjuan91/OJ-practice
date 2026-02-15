#include <bits/stdc++.h>
using namespace std;

constexpr int BITS = 15;
constexpr int MAXN = 1 << 16;

int ch[MAXN][2];
int cnt[MAXN];
int tot;

void trie_init() {
  memset(ch, 0, sizeof(ch));
  memset(cnt, 0, sizeof(cnt));
  tot = 1;
}

void trie_insert(int x, int delta) {
  int u = 1;
  for (int i = BITS; i >= 0; i--) {
    int b = (x >> i) & 1;
    if (!ch[u][b]) ch[u][b] = ++tot;
    u = ch[u][b];
    cnt[u] += delta;
  }
}

int trie_query(int x) {
  int u = 1, res = 0;
  for (int i = BITS; i >= 0; i--) {
    int b = (x >> i) & 1;
    int want = 1 - b;
    if (ch[u][want] && cnt[ch[u][want]] > 0) {
      res |= (1 << i);
      u = ch[u][want];
    } else {
      u = ch[u][b];
    }
  }
  return res;
}

class Solution {
 public:
  int maxXor(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> pref_xor(n + 1);
    for (int i = 0; i < n; i++) {
      pref_xor[i + 1] = pref_xor[i] xor nums[i];
    }
    trie_init();
    trie_insert(pref_xor[0], 1);
    map<int, int> cnt;
    int res = 0;
    for (int left = 0, right = 0; right < n; right++) {
      cnt[nums[right]]++;
      while (cnt.rbegin()->first - cnt.begin()->first > k) {
        trie_insert(pref_xor[left], -1);
        cnt[nums[left]]--;
        if (cnt[nums[left]] == 0) cnt.erase(nums[left]);
        left++;
      }
      res = max(res, trie_query(pref_xor[right + 1]));
      trie_insert(pref_xor[right + 1], 1);
    }
    return res;
  }
};

int main() { return 0; }