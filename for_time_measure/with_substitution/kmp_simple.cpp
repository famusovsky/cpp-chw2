#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> with_substitutions::knuthMorrisPratt(const std::string& str,
                                                      const std::string& substr) {
    int n = str.length();
    int m = substr.length();
    std::vector<int> result;
    if (m == 0 || n == 0) {
        return result;
    }
    std::vector<int> border = findPrefixFunction(substr);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        bool is_str_i_m_one_subst = str[-1 + i] == '?';
        bool is_substr_k_subst = substr[k] == '?';
        if (!is_str_i_m_one_subst && !is_substr_k_subst) {
            while (k > 0 && substr[k] != str[-1 + i]) {
                k = border[-1 + k];

                if (k > 0 && substr[k] == '?') {
                    is_substr_k_subst = true;
                    break;
                }
            }
        }

        if (is_str_i_m_one_subst || is_substr_k_subst || substr[k] == str[-1 + i]) {
            ++k;
        }

        if (k == m) {
            result.push_back(i - m);
            k = border[-1 + k];
        }
    }
    return result;
}
