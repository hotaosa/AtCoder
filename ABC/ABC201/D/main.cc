#include <iostream>
#include <vector>
#include <string>

void chmax(int &a, int b) { if (a < b) a = b; }
void chmin(int &a, int b) { if (a > b) a = b; }

int main() {
  const int INF = 1 << 30;
  
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<int> > a(h, std::vector<int>(w, 0));
  
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) a[i][j] = (s[j] == '+' ? 1 : -1);      
  }

  std::vector<std::vector<int> > opt(h, std::vector<int>(w, 0));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) opt[i][j] = ((i + j) & 1 ? INF : -INF);
  opt[h - 1][w - 1] = 0;
  
  for (int i = h - 1; i >= 0; --i) {
    for (int j = w - 1; j >= 0; --j) {
      if ((i + j) & 1) {
        if (i > 0) chmax(opt[i - 1][j], opt[i][j] + a[i][j]);
        if (j > 0) chmax(opt[i][j - 1], opt[i][j] + a[i][j]);
      } else {
        if (i > 0) chmin(opt[i - 1][j], opt[i][j] - a[i][j]);
        if (j > 0) chmin(opt[i][j - 1], opt[i][j] - a[i][j]);
      }
    }
  }

  if (opt[0][0] == 0) std::cout << "Draw" << std::endl;
  else if (opt[0][0] > 0) std::cout << "Takahashi" << std::endl;
  else std::cout << "Aoki" << std::endl;  
  return 0;
}
