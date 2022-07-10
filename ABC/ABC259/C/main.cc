#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, int> > run_length_encode(string s) {
  vector<pair<char, int> > res;
  char c = s[0];
  int cnt = 1;
  for (int i = 1; i < (int)s.length(); ++i) {
    if (s[i] == c) ++cnt;
    else {
      res.emplace_back(c, cnt);
      cnt = 1;
      c = s[i];
    }
  }
  res.emplace_back(c, cnt);
  return res;
}

int main() {
  string s, t;
  cin >> s >> t;
  auto s_comp = run_length_encode(s);
  auto t_comp = run_length_encode(t);

  bool possible = s_comp.size() == t_comp.size();
  if (possible) {
    for (int i = 0; i < (int)s_comp.size(); ++i) {
      possible &= s_comp[i].first == t_comp[i].first;
      possible &= (s_comp[i].second == t_comp[i].second || (s_comp[i].second > 1 && s_comp[i].second < t_comp[i].second));
    }
  }
  cout << (possible ? "Yes" : "No") << endl;
  return 0;
}