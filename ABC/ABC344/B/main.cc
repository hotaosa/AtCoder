#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> res;
  while (true) {
    int a;
    cin >> a;
    res.emplace_back(a);
    if (!a) {
      break;
    }
  }

  for (auto it = rbegin(res); it != rend(res); ++it) {
    cout << *it << endl;
  }
  return 0;
}