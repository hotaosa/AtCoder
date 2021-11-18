#include <iostream>
#include <string>
#include <map>

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    std::map<char, std::map<char, int> > ma;
    ma['R']['R'] = ma['R']['S'] = ma['S']['R'] = 'R';
    ma['S']['S'] = ma['S']['P'] = ma['P']['S'] = 'S';
    ma['P']['P'] = ma['P']['R'] = ma['R']['P'] = 'P';

    while (k--) {
        std::string t = s + s;
        for (int i = 0; i < n; ++i) s[i] = ma[t[i * 2]][t[i * 2 + 1]];
    }
    std::cout << s[0] << std::endl;
    return 0;    
}
