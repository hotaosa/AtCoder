#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int sum = 0, cur = n - 1, res = n;
  while (cur >= 0 && sum + a[cur] < 4) {
    sum += a[cur--];
    --res;
  }
  cout << res << endl;
  return 0;  
}