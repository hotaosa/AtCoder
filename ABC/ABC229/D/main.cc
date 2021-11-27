#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;

    int len = s.length();
    std::vector<int> cnt(len + 1, 0);
    for (int i = 1; i <= len; ++i) {
        cnt[i] = cnt[i - 1];
        if (s[i - 1] == '.') ++cnt[i];
    }

    int res = 0;
    for (int i = 1; i <= len; ++i) {
        int pos = std::upper_bound(cnt.begin(), cnt.end(), cnt[i - 1] + k) - cnt.begin();
        res = std::max(res, pos - i);
    }

    std::cout << res << std::endl;
    return 0;
}
