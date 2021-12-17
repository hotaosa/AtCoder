#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.length();

    std::vector<std::vector<int> > pos(26);
    for (int i = 0; i < n; ++i) pos[s[i] - 'a'].push_back(i);

    long long res = 0LL;
    int cur = -1;
    for (char c : t) {
        if (pos[c - 'a'].empty()) { std::cout << "-1" << std::endl; return 0; }
        auto p = std::upper_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), cur);
        if (p != pos[c - 'a'].end()) { res += *p - cur; cur = *p; }
        else { res += n - cur + pos[c - 'a'][0]; cur = pos[c - 'a'][0]; }
    }

    std::cout << res << std::endl;
    return 0;
}
