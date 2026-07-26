#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> basicCalculatorIV(string expression, vector<string>& evalvars,
                                   vector<int>& evalints) {
    for (size_t i = 0; i < evalvars.size(); i++) {
      eva_[evalvars[i]] = evalints[i];
    }
    size_t i = 0;
    return format(evaluate(expression, i));
  }

 private:
  using Term = vector<string>;
  using Poly = map<Term, int64_t>;
  unordered_map<string, int64_t> eva_;

  static Poly constant(int64_t x) {
    Poly p;
    if (x != 0) p[Term{}] = x;
    return p;
  }

  static void add_into(Poly& a, const Poly& b, int64_t sign) {
    for (const auto& [t, c] : b) {
      int64_t& v = a[t];
      v += sign * c;
      if (v == 0) a.erase(t);
    }
  }

  static Poly mul(const Poly& a, const Poly& b) {
    Poly res;
    for (const auto& [ta, va] : a) {
      for (const auto& [tb, vb] : b) {
        Term t;
        t.reserve(ta.size() + tb.size());
        t.insert(t.end(), ta.begin(), ta.end());
        t.insert(t.end(), tb.begin(), tb.end());
        sort(t.begin(), t.end());
        int64_t& v = res[t];
        v += va * vb;
        if (v == 0) res.erase(t);
      }
    }
    return res;
  }

  Poly evaluate(const string& s, size_t& i) {
    vector<Poly> stac;
    Poly cur;
    char op = '+';

    auto flush = [&]() {
      if (op == '*') {
        stac.back() = mul(stac.back(), cur);
      } else if (op == '+') {
        stac.push_back(Poly{});
        add_into(stac.back(), cur, 1);
      } else if (op == '-') {
        stac.push_back(Poly{});
        add_into(stac.back(), cur, -1);
      }
      cur.clear();
    };

    while (i < s.size() and s[i] != ')') {
      if (s[i] == ' ') {
        ++i;
      } else if (isdigit(static_cast<unsigned char>(s[i]))) {
        int64_t v = 0;
        while (i < s.size() and isdigit(static_cast<unsigned char>(s[i]))) {
          v = v * 10 + (s[i] - '0');
          ++i;
        }
        cur = constant(v);
      } else if (islower(static_cast<unsigned char>(s[i]))) {
        string name;
        while (i < s.size() and islower(static_cast<unsigned char>(s[i]))) {
          name += s[i];
          ++i;
        }
        if (eva_.count(name)) {
          cur = constant(eva_[name]);
        } else {
          cur.clear();
          cur[Term{name}] = 1;
        }
      } else if (s[i] == '(') {
        ++i;
        cur = evaluate(s, i);
        ++i;
      } else {
        flush();
        op = s[i];
        ++i;
      }
    }

    flush();
    Poly res;
    for (const auto& p : stac) add_into(res, p, 1);
    return res;
  }

  vector<string> format(const Poly& p) {
    vector<pair<Term, int64_t>> terms(p.begin(), p.end());
    sort(terms.begin(), terms.end(), [](const auto& lhs, const auto& rhs) {
      if (lhs.first.size() != rhs.first.size()) {
        return lhs.first.size() > rhs.first.size();
      }
      return lhs.first < rhs.first;
    });
    vector<string> res;
    for (const auto& [t, c] : terms) {
      if (c == 0) continue;
      string cur = to_string(c);
      for (const auto& s : t) cur += "*" + s;
      res.push_back(cur);
    }

    return res;
  }
};

int main() { return 0; }