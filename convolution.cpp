#include <bits/stdc++.h>
using namespace std;

const double kPI = acos(-1);
const int kMax = 2e6 + 5;
typedef complex<double> Complex;

Complex x1[3][kMax], x2[3][kMax];
int ans[kMax];
string str;
int n;
int bit = 2, rev[kMax];

void get_rev() {
  memset(rev, 0, sizeof(rev));
  while (bit <= n + n) bit <<= 1;
  for (int i = 0; i < bit; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | (bit >> 1) * (i & 1);
  }
}

void FFT(Complex *arr, int op) {
  for (int i = 0; i < bit; ++i) {
    if (i < rev[i]) swap(arr[i], arr[rev[i]]);
  }
  for (int mid = 1; mid < bit; mid <<= 1) {
    Complex wn = Complex(cos(kPI / mid), op * sin(kPI / mid));
    for (int j = 0; j < bit; j += mid << 1) {
      Complex w(1, 0);
      for (int k = 0; k < mid; ++k, w = w * wn) {
        Complex x = arr[j + k], y = w * arr[j + k + mid];
        arr[j + k] = x + y, arr[j + k + mid] = x - y;
      }
    }
  }
  if (op == -1) {
    for (int i = 0; i < bit; ++i) {
      arr[i] /= bit;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> str, n = str.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      x1[j][n - i - 1] = str[i] == 'a' + j;
      x2[j][i] = x1[j][n - i - 1];
    }
  }

  get_rev();
  for (int i = 0; i < 3; i++) {
    FFT(x1[i], 1), FFT(x2[i], 1);
  }
  for (int i = 0; i < bit; i++) {
    for (int j = 0; j < 3; j++) {
      x1[j][i] *= x2[j][i];
    }
  }
  for (int i = 0; i < 3; i++) {
    FFT(x1[i], -1);
  }

  int max_val = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      ans[i] += (int)(x1[j][n + i - 1].real() + 0.5);
    }
    max_val = max(max_val, ans[i]);
  }

  cout << max_val << '\n';
  for (int i = 1; i < n; i++) {
    if (ans[i] == max_val) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  return 0;
}