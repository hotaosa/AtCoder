#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    std::string s;
    long long k;
    std::cin >> s >> k;

    std::vector<int> pos_y;
    for (int i = 0; i < (int)s.length(); ++i) if (s[i] == 'Y') pos_y.push_back(i);
    if (pos_y.empty()) { std::cout << "0" << std::endl; return 0; }

    std::vector<long long> vec(pos_y.size()), tot(pos_y.size());
    tot[0] = vec[0] = pos_y[0];
    for (int i = 1; i < (int)pos_y.size(); ++i) {
        vec[i] = pos_y[i] - i;
        tot[i] = tot[i - 1] + vec[i];
    }

    auto can_make = [&](int m) -> bool {
        for (int i = 0; i <= (int)vec.size() - m; ++i) {
            int left = i, right = i + m - 1, med = left + m / 2;
            long long cur = vec[med] * (med - left) - (tot[med - 1] - (i > 0 ? tot[i - 1] : 0LL));
            cur += tot[right] - tot[med] - vec[med] * (right - med);
            if (cur <= k) return true;
        }
        return false;
    };

    int ok = 0, ng = pos_y.size() + 1;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if (can_make(mid)) ok = mid;
        else ng = mid;
    }

    std::cout << ok << std::endl;
    return 0;
}
