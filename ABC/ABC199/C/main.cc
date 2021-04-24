#include <bits/stdc++.h>

// スワップ対象のインデックスを前後反転
int reverse(int &a, int n) {
  if (a < n) return a + n;
  else return a - n;
}

int main() {
  int n, q;
  std::string s;
  std::cin >> n >> s >> q;

  bool rev = false;                     // 前後反転しているかどうか

  for (int i = 0; i < q; ++i) {
    int t, a, b;
    std::cin >> t >> a >> b;
    --a; --b;                           // 0-indexedにする
    if (t == 1) {
      if (rev) {
        a = reverse(a, n);
        b = reverse(b, n);
      }
      std::swap(s[a], s[b]);            // a文字目とb文字目を入れ替え
    }
    else rev = !rev;                    // t = 2 なら反転/非反転を切り替え
  }

  // 最終状態で前後反転の場合は普通に反転する
  if (rev) {
    std::string ss = s.substr(n, n);    // 後ろ半分を抽出
    ss += s.substr(0, n);               // 前半分を後ろにくっつける
    s = ss;
  }
  std::cout << s << std::endl;
  return 0;
}
