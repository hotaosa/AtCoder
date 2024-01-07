#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};

  vector res(n, vector<int>(n, -1));
  res[0][0] = 1;

  int x = 0, y = 0, d = 0;
  for (int i = 2; i < n * n; ++i) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n || res[nx][ny] != -1) {
      d = (d + 1) % 4;
      nx = x + dx[d];
      ny = y + dy[d];
    }
    res[x = nx][y = ny] = i;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == n / 2 && j == n / 2) {
        cout << "T ";
      } else {
        cout << res[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}