#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> normal::knuthMorrisPrattAdvanced(const std::string& str, const std::string& substr, int64_t& count) {
    int n = str.length();
    int m = substr.length();
    std::vector<int> result;
    if (m == 0 || n == 0) {
        return result;
    }
    std::vector<int> border = findBorderFunction(substr, count);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        while (k > 0 && substr[k] != str[-1 + i]) {
            k = border[-1 + k];
            ++count;
        }
        ++count;
        if (substr[k] == str[-1 + i]) {
            k++;
        }
        ++count;
        if (k == m) {
            result.push_back(i - m);
            k = border[-1 + k];
        }
    }
    return result;
}
