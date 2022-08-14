#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h1, w1;
  cin >> h1 >> w1;
  vector<vector<int> > a(h1, vector<int>(w1));
  for (int i = 0; i < h1; ++i) for (int j = 0; j < w1; ++j) cin >> a[i][j];

  int h2, w2;
  cin >> h2 >> w2;
  vector<vector<int> > b(h2, vector<int>(w2));
  for (int i = 0; i < h2; ++i) for (int j = 0; j < w2; ++j) cin >> b[i][j];

  for (int bit_r = 1; bit_r < (1 << h1); ++bit_r) {
    for (int bit_c = 1; bit_c < (1 << w1); ++bit_c) {
      vector<int> list_r, list_c;
      for (int i = 0; i < h1; ++i) if (bit_r & (1 << i)) list_r.push_back(i);
      for (int i = 0; i < w1; ++i) if (bit_c & (1 << i)) list_c.push_back(i);
      vector<vector<int> > cur_a(list_r.size(), vector<int>(list_c.size()));
      for (int i = 0; i < list_r.size(); ++i) {
        for (int j = 0; j < list_c.size(); ++j) {
          cur_a[i][j] = a[list_r[i]][list_c[j]];
        }
      }
      if (cur_a == b) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;  
  return 0;
}
