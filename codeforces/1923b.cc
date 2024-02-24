#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    struct Monster {
      int blood, distance;
      Monster(int blood, int distance) : blood(blood), distance(distance) {}
      Monster() {}
      bool operator<(const Monster &other) const {
        return distance < other.distance;
      }
    };
    vector<Monster> monsters(n);
    for (int i = 0; i < n; i++) {
      cin >> monsters[i].blood;
    }
    for (int i = 0; i < n; i++) {
      cin >> monsters[i].distance;
      monsters[i].distance = llabs(monsters[i].distance);
    }
    sort(monsters.rbegin(), monsters.rend());
    bool ok = true;
    for (int seconds = 0; !monsters.empty() && ok; seconds++) {
      int bullets = m;
      while (bullets > 0 && !monsters.empty()) {
        auto monster = monsters.back();
        monsters.pop_back();
        if (monster.distance - seconds <= 0) {
          ok = false;
          break;
        }
        if(monster.blood > bullets) {
          monster.blood -= bullets;
          monsters.push_back(monster);
          bullets = 0;
        } else {
          bullets -= monster.blood;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
