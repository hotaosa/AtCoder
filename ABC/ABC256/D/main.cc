#include <iostream>
#include <vector>

using namespace std;
constexpr int SIZ = 200001;

int main() {
  int n;
  cin >> n;
  vector<int> sum(SIZ, 0);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    ++sum[l];
    --sum[r];
  }

  for (int i = 1; i < SIZ; ++i) {    
    sum[i] += sum[i - 1];
    if (sum[i] > 0 && sum[i - 1] == 0) cout << i << " ";
    if (sum[i] == 0 && sum[i - 1] > 0) cout << i << endl;
  }
  return 0;
}