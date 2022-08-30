#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<long long> score;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    score.push_back(b);
    score.push_back(a - b);
  }

  sort(score.rbegin(), score.rend());
  for (int i = 1; i < 2 * n; ++i) score[i] += score[i - 1];
  cout << score[k - 1] << endl;  
  return 0;
}
