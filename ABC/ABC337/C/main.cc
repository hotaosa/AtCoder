#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int v = -1;
  vector<int> nx(n, -1);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a == -1) {
      v = i;
    } else {
      nx[--a] = i;
    }
  }

  while (v != -1) {
    cout << v + 1 << " ";
    v = nx[v];
  }

  return 0;
}