#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> with_substitutions::knuthMorrisPrattAdvanced(const std::string& str, const std::string& substr) {
    int n = str.length();
    int m = substr.length();
    std::vector<int> result;
    if (m == 0 || n == 0) {
        return result;
    }
    std::vector<int> border = findBorderFunction(substr);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        bool is_str_i_subst = str[-1 + i] == '?';
        // TODO: make normal compare
        if (!is_str_i_subst) {
            while (k > 0 && substr[k] != str[-1 + i] && substr[k] != '?') {
                k = border[-1 + k];
            }
        }
        if (is_str_i_subst) {
            ++k;
        } else {
            if (substr[k] == str[-1 + i] || substr[k] == '?') {
                ++k;
            }
        }
        if (k == m) {
            result.push_back(i - m);
            k = border[-1 + k];
        }
    }
    return result;
}
