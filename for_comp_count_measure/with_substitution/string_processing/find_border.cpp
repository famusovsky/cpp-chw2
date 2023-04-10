#include <vector>
#include <string>
#include "functions.h"

std::vector<int> findBorderFunction(const std::string& str, int64_t& count) {
    int n = str.length();
    std::vector<int> pi = findPrefixFunction(str, count);
    std::vector<int> border(n);
    border[0] = 0;
    for (int i = 1; i < n; ++i) {
        // TODO: make normal counting -- you should not do 3 comparisons everytime
        if (str[pi[i]] != str[i + 1] && str[pi[i]] != '?' && str[i + 1] != '?') {
            border[i] = pi[i];
        } else {
            border[i] = border[pi[i]];
        }
        count += 3;
    }
    return border;
}