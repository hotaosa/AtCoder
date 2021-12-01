#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int> > col(h, std::vector<int>(w, 0));
    for (int i = 0; i < h; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < w; ++j) {
            if (s[j] == 'R') col[i][j] = 1;
            else if (s[j] == 'B') col[i][j] = -1;
        }
    }

    auto sweep = [&](int r, int c) -> int {
        bool exist_red = false, exist_blue = false;
        while (r < h && c >= 0) {
            if (col[r][c] == 1) exist_red = true;
            else if (col[r][c] == -1) exist_blue = true;
            ++r;
            --c;
        }
        if (exist_red && exist_blue) return 0;
        else if (exist_red || exist_blue) return 1;
        else return 2;
    };

    atcoder::modint998244353 res = (col[0][0] ? 1 : 2);
    int cur_r = 0, cur_c = 0;
    while (cur_c < w - 1) {
        ++cur_c;
        res *= sweep(cur_r, cur_c);
    }
    while (cur_r < h - 1) {
        ++cur_r;
        res *= sweep(cur_r, cur_c);
    }
    std::cout << res.val() << std::endl;
    return 0;
}
