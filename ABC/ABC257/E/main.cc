#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cost(9);
  int min_cost = n;
  for (int i = 0; i < 9; ++i) {
    cin >> cost[i];
    min_cost = min(min_cost, cost[i]);
  }

  string res = "";
  while (n >= min_cost) {
    int add = 0;
    for (int i = 0; i < 9; ++i) {
      if ((n - cost[i]) / min_cost == (n - min_cost) / min_cost && n >= cost[i]) add = i + 1;
    }
    res += '0' + add;
    n -= cost[add - 1];
  }

  cout << res << endl;
  return 0;
}