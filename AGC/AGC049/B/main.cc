#include <iostream>
#include <vector>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    if (s == t) { std::cout << "0" << std::endl; return 0; }
    
    std::map<std::string, std::vector<int> > pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') pos[s].push_back(i);
        if (t[i] == '1') pos[t].push_back(i);        
    }

    if (pos[s].size() < pos[t].size() || (pos[s].size() + pos[t].size()) & 1) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    for (auto ps = pos[s].rbegin(), pt = pos[t].rbegin(); pt != pos[t].rend(); ++ps, ++pt) {
        if (*ps < *pt) {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    int res = 0;
    auto itr_s = pos[s].begin(), itr_t = pos[t].begin();
    while (itr_t != pos[t].end()) {
        if (*itr_s >= *itr_t) {
            res += *itr_s - *itr_t;
            ++itr_s;
            ++itr_t;
        } else {
            auto nx = itr_s;
            ++nx;
            res += *nx - *itr_s;
            ++itr_s;
            ++itr_s;
        }
    }

    while (itr_s != pos[s].end()) {
        auto nx = itr_s;
        ++nx;
        res += *nx - *itr_s;
        ++itr_s;
        ++itr_s;
    }

    std::cout << res << std::endl;
    return 0;
}
