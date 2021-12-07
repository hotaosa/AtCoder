#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int h, w;
    std::cin >> h >> w;
    int n = h * w;

    std::vector<bool> is_white(n, false);
    for (int i = 0; i < h; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < w; ++j) if (s[j] == '.') is_white[i * w + j] = true;
    }

    atcoder::dsu uf(n);

    auto merge = [&](int i, int j) -> void {
        if (is_white[i] != is_white[j]) uf.merge(i, j);
    };
    
    for (int i = 0; i < n; ++i) {
        if (i % w > 0) merge(i, i - 1);
        if (i % w < w - 1) merge(i, i + 1);
        if (i / w > 0) merge(i, i - w);
        if (i / w < h - 1) merge(i, i + w);
    }

    std::map<int, std::pair<long long, long long> > ma;
    for (int i = 0; i < n; ++i) {
        if (is_white[i]) ++ma[uf.leader(i)].first;
        else ++ma[uf.leader(i)].second;
    }

    long long res = 0LL;
    for (auto &p : ma) res += p.second.first * p.second.second;
    std::cout << res << std::endl;
    return 0;
}
