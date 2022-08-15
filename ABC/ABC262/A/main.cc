#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int y;
  cin >> y;
  for (int i = 0; i < 4; ++i) {
    int yy = y + i;
    if (yy % 4 == 2) {
      cout << yy << endl;
      return 0;
    }
  }    
  return 0;
}
