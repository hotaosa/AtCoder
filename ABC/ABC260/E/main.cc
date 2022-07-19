#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;  
  vector<int> mxb(m + 1, 0);
  int a_max = 0, b_min = m;

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a_max = max(a_max, a);
    b_min = min(b_min, b);
    mxb[a] = max(mxb[a], b);    
  }
  for (int i = 1; i <= m; ++i) mxb[i] = max(mxb[i - 1], mxb[i]);

  vector<int> res(m + 2, 0);
  for (int l = 1; l <= b_min; ++l) {
    int r = max(a_max, mxb[l - 1]);
    ++res[r - l + 1];
    --res[m - l + 2];
  }

  for (int i = 1; i <= m; ++i) {
    res[i] += res[i - 1];
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;  
}