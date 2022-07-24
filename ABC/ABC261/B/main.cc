#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (auto &p : vs) cin >> p;

  bool correct = true;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (vs[i][j] == 'D') correct &= vs[j][i] == 'D';
      else if (vs[i][j] == 'W') correct &= vs[j][i] == 'L';
      else correct &= vs[j][i] == 'W';
    }
  }

  cout << (correct ? "correct" : "incorrect") << endl;
  return 0;
}