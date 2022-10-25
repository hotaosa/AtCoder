#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<int> res(w, 0);
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == '#') ++res[j];
    }
  }

  for (int i = 0; i < w; ++i) cout << res[i] << " ";
  cout << endl;  
  return 0;
}
