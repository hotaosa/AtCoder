#include <iostream>
#include <vector>

using namespace std;

void Func(int sr, int sc, int size, vector<string> &res) {
  if (size == 1) {
    res[sr][sc] = '#';
    return;
  }

  int step = size / 3;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == 1 && j == 1) continue;
      Func(sr + i * step, sc + j * step, step, res);
    }
  }
}

int main() {
  int n;
  cin >> n;
  int size = 1;
  for (int i = 0; i < n; ++i) size *= 3;

  vector res(size, string(size, '.'));
  Func(0, 0, size, res);

  for (auto &s : res) {
    cout << s << endl;
  }
  return 0;
}
