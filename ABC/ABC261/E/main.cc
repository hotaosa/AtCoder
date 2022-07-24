#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;

  vector<vector<vector<int> > > sumop(n + 1, vector<vector<int> >(30, vector<int>(2, 0)));
  for (int i = 0; i < 30; ++i) sumop[0][i][1] = 1;

  for (int i = 0; i < n; ++i) {
    int t, a;
    cin >> t >> a;
    for (int j = 0; j < 30; ++j) {
      int bit = a >> j & 1;
      if (t == 1) for (int k = 0; k < 2; ++k) sumop[i + 1][j][k] = sumop[i][j][k] & bit;
      else if (t == 2) for (int k = 0; k < 2; ++k) sumop[i + 1][j][k] = sumop[i][j][k] | bit;
      else for (int k = 0; k < 2; ++k) sumop[i + 1][j][k] = sumop[i][j][k] ^ bit;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 30; ++j) {
      int bit = c >> j & 1;
      if (sumop[i][j][bit]) c |= 1 << j;
      else c &= ~(1 << j);
    }
    cout << c << endl;
  }
  return 0;  
}