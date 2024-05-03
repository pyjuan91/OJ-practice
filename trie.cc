#include <bits/stdc++.h>
using namespace std;

class Trie {
 public:
  static const int kMax = 5e5 + 1;
  int** nex;
  int* exist;
  int cnt;

  Trie() {
    nex = new int*[kMax];
    for (int i = 0; i < kMax; i++) {
      nex[i] = new int[26];
      memset(nex[i], 0, sizeof(int) * 26);
    }
    exist = new int[kMax];
    memset(exist, 0, sizeof(int) * kMax);
    cnt = 0;
  }

  void insert(const string& s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    exist[p] = 1;
  }

  int find(const string& s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    if (!exist[p]) return 0;
    if (exist[p] == 1) {
      exist[p] = 2;
      return 1;
    }
    return -1;
  }
};