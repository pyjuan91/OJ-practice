#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    // Read n and d.
    // n is given up to 1e9; we don't compute n! but only use n to determine
    // divisibility conditions.
    long long n;
    int d;
    cin >> n >> d;

    bool divisibleBy3 = (n >= 3) || (n == 2 && ((2 * d) % 3 == 0));
    bool divisibleBy5 = (d == 5);
    bool divisibleBy7 = (n >= 3) || (n == 2 && d == 7);
    bool divisibleBy9 = false;
    if (n >= 6) {
      divisibleBy9 = true;
    } else if (n == 2) {
      divisibleBy9 = ((2 * d) % 9 == 0);
    } else if (n == 3) {
      divisibleBy9 = ((6 * d) % 9 == 0);
    } else if (n == 4) {
      divisibleBy9 = ((6 * d) % 9 == 0);
    } else if (n == 5) {
      divisibleBy9 = ((3 * d) % 9 == 0);
    }

    cout << 1 << " ";
    if (divisibleBy3) cout << 3 << " ";
    if (divisibleBy5) cout << 5 << " ";
    if (divisibleBy7) cout << 7 << " ";
    if (divisibleBy9) cout << 9 << " ";
    cout << "\n";
  }

  return 0;
}
