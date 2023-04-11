#include <vector>
#include <string>
#include "functions.h"

std::vector<int> findBorderFunction(const std::string& str, int64_t& count) {
    int n = str.length();
    std::vector<int> pi = findPrefixFunction(str, count);
    std::vector<int> border(n);
    border[0] = 0;
    for (int i = 1; i < n; ++i) {
        ++count;
        if (str[pi[i]] != '?') {
            border[i] = border[pi[i]];
            continue;
        }
        ++count;
        if (str[i + 1] != '?') {
            border[i] = border[pi[i]];
            continue;
        }
        ++count;
        if (str[pi[i]] != str[i + 1]) {
            border[i] = pi[i];
        } else {
            border[i] = border[pi[i]];
        }
    }
    return border;
}