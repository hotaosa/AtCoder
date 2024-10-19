#include <iostream>

int main() {
  int n, q;
  std::cin >> n >> q;

  int l = 0, r = 1, res = 0;

  for (int i = 0; i < q; ++i) {
    char h;
    int t;
    std::cin >> h >> t;
    --t;

    int dl = (t - l + n) % n;
    int dr = (t - r + n) % n;
    if (h == 'L') {
      if (dl < dr) {
        res += dl;
      } else {
        res += n - dl;
      }
      l = t;
    } else {
      if (dr < dl) {
        res += dr;
      } else {
        res += n - dr;
      }
      r = t;
    }
  }

  std::cout << res << "\n";

  return 0;
}