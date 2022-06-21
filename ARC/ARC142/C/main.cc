#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dist_3;
  int dist_min = n * 2;
  for (int i = 3; i <= n; ++i) {
    int d1, d2;
    cout << "? 1 " << i << endl;
    cin >> d1;
    cout << "? 2 " << i << endl;
    cin >> d2;
    dist_min = min(dist_min, d1 + d2);
    if (d1 + d2 == 3) dist_3.push_back(i);
  }

  if (dist_min == 3) {
    if (dist_3.size() == 2) {
      int d;
      cout << "? " << dist_3[0] << " " << dist_3[1] << endl;
      cin >> d;
      if (d != 1) dist_min = 1;
    } else {
      dist_min = 1;
    }    
  }
  cout << "! " << dist_min << endl;
  return 0;
}