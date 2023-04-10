#include <string>
#include <vector>
#include "algorithms.h"

std::vector<int> normal::naiveAlgorithm(const std::string& str, const std::string& substr, int64_t& count) {
    std::vector<int> matches;

    for (int i = 0; i <= str.length() - substr.length(); ++i) {
        int j;
        for (j = 0; j < substr.length(); ++j) {
            ++count;
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == substr.length()) {
            matches.push_back(i);
        }
    }

    return matches;
}
