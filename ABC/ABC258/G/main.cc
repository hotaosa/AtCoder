#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bitset<3000> > vb(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) vb[i][j] = s[j] - '0';
  }

  long long res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (vb[i][j]) res += (vb[i] & vb[j]).count();
    }
  }
  cout << res / 3 << endl;
  return 0;
}