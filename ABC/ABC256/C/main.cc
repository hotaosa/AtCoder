#include <iostream>

using namespace std;
constexpr int MAX = 30;

int main() {
  int h1, h2, h3, w1, w2, w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

  int res = 0;
  for (int a = 1; a <= MAX; ++a) {
    for (int b = 1; b <= MAX; ++b) {
      for (int d = 1; d <= MAX; ++d) {
        for (int e = 1; e <= MAX; ++e) {
          int c = h1 - a - b;
          int f = h2 - d - e;
          int g = w1 - a - d;
          int h = w2 - b - e;
          int i1 = h3 - g - h;
          int i2 = w3 - c - f;
          if (c > 0 && f > 0 && g > 0 && h > 0 && i1 >0 && i1 == i2) ++res;
        }
      }
    }
  }
  cout << res << endl;  
  return 0;
}