#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> with_substitutions::knuthMorrisPratt(const std::string& str, const std::string& substr,
                                          int64_t& count) {
    int n = str.length();
    int m = substr.length();
    std::vector<int> result;
    if (m == 0 || n == 0) {
        return result;
    }
    std::vector<int> border = findPrefixFunction(substr, count);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        bool is_str_i_subst = str[-1 + i] == '?';
        ++count;
        // TODO: make normal counting
        if (!is_str_i_subst) {
            while (k > 0 && substr[k] != str[-1 + i] && substr[k] != '?') {
                k = border[-1 + k];
                count += 2;
            }
            count += 2;
        }
        if (is_str_i_subst) {
            ++k;
        } else {
            if (substr[k] == str[-1 + i] || substr[k] == '?') {
                ++k;
            }
            count += 2;
        }
        if (k == m) {
            result.push_back(i - m);
            k = border[-1 + k];
        }
    }
    return result;
}
