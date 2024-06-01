#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class SuffixArray {
 public:
  SuffixArray(const std::string &text) : text(text) { buildSuffixArray(); }

  const std::vector<int> &getSuffixArray() const { return suffixArray; }

 private:
  std::string text;
  std::vector<int> suffixArray;

  void buildSuffixArray() {
    int n = text.size();
    std::vector<int> s(n + 3);
    for (int i = 0; i < n; ++i) s[i] = text[i];
    suffixArray.resize(n);
    suffixArrayDC3(s, suffixArray, n, 256);
  }

  static void suffixArrayDC3(const std::vector<int> &s, std::vector<int> &SA,
                             int n, int K) {
    int n0 = (n + 2) / 3;
    int n1 = (n + 1) / 3;
    int n2 = n / 3;
    int n02 = n0 + n2;

    std::vector<int> s12(n02 + 3, 0);
    std::vector<int> SA12(n02 + 3, 0);
    std::vector<int> s0(n0, 0);
    std::vector<int> SA0(n0, 0);

    for (int i = 0, j = 0; i < n + (n0 - n1); ++i)
      if (i % 3 != 0) s12[j++] = i;

    radixPass(s12, SA12, s, 2, n02, K);
    radixPass(SA12, s12, s, 1, n02, K);
    radixPass(s12, SA12, s, 0, n02, K);

    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; ++i) {
      if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
        name++;
        c0 = s[SA12[i]];
        c1 = s[SA12[i] + 1];
        c2 = s[SA12[i] + 2];
      }
      if (SA12[i] % 3 == 1) {
        s12[SA12[i] / 3] = name;
      } else {
        s12[SA12[i] / 3 + n0] = name;
      }
    }

    if (name < n02) {
      suffixArrayDC3(s12, SA12, n02, name);
      for (int i = 0; i < n02; ++i) s12[SA12[i]] = i + 1;
    } else {
      for (int i = 0; i < n02; ++i) SA12[s12[i] - 1] = i;
    }

    for (int i = 0, j = 0; i < n02; ++i)
      if (SA12[i] < n0) s0[j++] = 3 * SA12[i];

    radixPass(s0, SA0, s, 0, n0, K);

    for (int p = 0, t = n0 - n1, k = 0; k < n; ++k) {
      int i = getI(SA12, t, n0);
      int j = SA0[p];
      if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3])
                       : leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j],
                             s[j + 1], s12[j / 3 + n0])) {
        SA[k] = i;
        if (++t == n02) {
          for (++k; p < n0; ++p, ++k) SA[k] = SA0[p];
        }
      } else {
        SA[k] = j;
        if (++p == n0) {
          for (++k; t < n02; ++t, ++k) SA[k] = getI(SA12, t, n0);
        }
      }
    }
  }

  static void radixPass(const std::vector<int> &a, std::vector<int> &b,
                        const std::vector<int> &r, int offset, int n, int K) {
    std::vector<int> count(K + 1, 0);
    for (int i = 0; i < n; ++i) count[r[a[i] + offset]]++;
    for (int i = 0, sum = 0; i <= K; ++i) {
      int t = count[i];
      count[i] = sum;
      sum += t;
    }
    for (int i = 0; i < n; ++i) b[count[r[a[i] + offset]]++] = a[i];
  }

  static int getI(const std::vector<int> &SA12, int t, int n0) {
    return SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2;
  }

  static bool leq(int a1, int a2, int b1, int b2) {
    return a1 < b1 || (a1 == b1 && a2 <= b2);
  }

  static bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3));
  }
};

int main() {
  std::string text = "banana";
  SuffixArray sa(text);
  for (int i : sa.getSuffixArray()) {
    std::cout << i << " ";
  }
  return 0;
}
