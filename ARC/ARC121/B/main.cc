#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    n <<= 1;
    std::map<char, std::vector<long long> > ma;
    for (int i = 0; i < n; ++i) {
        long long a;
        char c;
        std::cin >> a >> c;
        ma[c].push_back(a);
    }

    int r = ma['R'].size(), g = ma['G'].size(), b = ma['B'].size();
    if (!(r & 1) && !(g & 1) && !(b & 1)) { std::cout << "0" << std::endl; }
    else {
        int cnt = 0;
        std::vector<std::vector<long long> > v(3);
        for (auto &p : ma) {
            std::sort(p.second.begin(), p.second.end());
            if (p.second.size() & 1) v[cnt++] = p.second;
            else v[2] = p.second;
        }
        assert(cnt = 2);

        long long res = 1LL << 60;
        for (auto a0 : v[0]) {
            auto p = std::lower_bound(v[1].begin(), v[1].end(), a0);
            if (p != v[1].end()) res = std::min(res, *p - a0);
            if (p != v[1].begin()) res = std::min(res, a0 - *(--p));
        }

        long long r1 = 1LL << 60;
        for (auto a0 : v[0]) {
            auto p = std::lower_bound(v[2].begin(), v[2].end(), a0);
            if (p != v[2].end()) r1 = std::min(r1, *p - a0);
            if (p != v[2].begin()) r1 = std::min(r1, a0 - *(--p));
        }

        long long r2 = 1LL << 60;
        for (auto a1 : v[1]) {
            auto p = std::lower_bound(v[2].begin(), v[2].end(), a1);
            if (p != v[2].end()) r2 = std::min(r2, *p - a1);
            if (p != v[2].begin()) r2 = std::min(r2, a1 - *(--p));
        }

        res = std::min(res, r1 + r2);
        std::cout << res << std::endl;
    }
    return 0;
}
