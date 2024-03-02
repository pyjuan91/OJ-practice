#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Cube {
  int x1, y1, z1, x2, y2, z2;
  Cube(int x, int y, int z)
      : x1(x), y1(y), z1(z), x2(x + 7), y2(y + 7), z2(z + 7) {}
};

int volumeOfIntersection(Cube c1, Cube c2) {
  int x_overlap = max(0LL, min(c1.x2, c2.x2) - max(c1.x1, c2.x1));
  int y_overlap = max(0LL, min(c1.y2, c2.y2) - max(c1.y1, c2.y1));
  int z_overlap = max(0LL, min(c1.z2, c2.z2) - max(c1.z1, c2.z1));
  return x_overlap * y_overlap * z_overlap;
}

int volumeOfIntersection(Cube c1, Cube c2, Cube c3) {
  int x_overlap =
      max(0LL, min({c1.x2, c2.x2, c3.x2}) - max({c1.x1, c2.x1, c3.x1}));
  int y_overlap =
      max(0LL, min({c1.y2, c2.y2, c3.y2}) - max({c1.y1, c2.y1, c3.y1}));
  int z_overlap =
      max(0LL, min({c1.z2, c2.z2, c3.z2}) - max({c1.z1, c2.z1, c3.z1}));
  return x_overlap * y_overlap * z_overlap;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int exact_one, exact_two, exact_three;
  cin >> exact_one >> exact_two >> exact_three;

  auto kazuha = [&](int c2_x, int c2_y, int c2_z, int c3_x, int c3_y,
                    int c3_z) {
    Cube c1(0, 0, 0), c2(c2_x, c2_y, c2_z), c3(c3_x, c3_y, c3_z);
    int volume_c1_c2_c3 = volumeOfIntersection(c1, c2, c3);
    int volume_onely_c1_c2 = volumeOfIntersection(c1, c2) - volume_c1_c2_c3;
    int volume_onely_c1_c3 = volumeOfIntersection(c1, c3) - volume_c1_c2_c3;
    int volume_onely_c2_c3 = volumeOfIntersection(c2, c3) - volume_c1_c2_c3;
    int volume_onely_c1 =
        7 * 7 * 7 - volume_onely_c1_c2 - volume_onely_c1_c3 - volume_c1_c2_c3;
    int volume_onely_c2 =
        7 * 7 * 7 - volume_onely_c1_c2 - volume_onely_c2_c3 - volume_c1_c2_c3;
    int volume_onely_c3 =
        7 * 7 * 7 - volume_onely_c1_c3 - volume_onely_c2_c3 - volume_c1_c2_c3;
    int e1 = volume_onely_c1 + volume_onely_c2 + volume_onely_c3;
    int e2 = volume_onely_c1_c2 + volume_onely_c1_c3 + volume_onely_c2_c3;
    int e3 = volume_c1_c2_c3;
    return e1 == exact_one && e2 == exact_two && e3 == exact_three;
  };

  for (int c2_x = 0; c2_x <= 7; c2_x++) {
    for (int c2_y = 0; c2_y <= 7; c2_y++) {
      for (int c2_z = 0; c2_z <= 7; c2_z++) {
        for (int c3_x = -7; c3_x <= 7; c3_x++) {
          for (int c3_y = -7; c3_y <= 7; c3_y++) {
            for (int c3_z = -7; c3_z <= 7; c3_z++) {
              if (kazuha(c2_x, c2_y, c2_z, c3_x, c3_y, c3_z)) {
                cout << "Yes\n";
                cout << 0 << ' ' << 0 << ' ' << 0 << ' ';
                cout << c2_x << ' ' << c2_y << ' ' << c2_z << ' ';
                cout << c3_x << ' ' << c3_y << ' ' << c3_z << '\n';
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
