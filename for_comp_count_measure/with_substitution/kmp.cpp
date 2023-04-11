#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> with_substitutions::kMP(const std::string& str, const std::string& substr, int64_t& count, bool is_standart_or_advanced) {
    int n = str.length();
    int m = substr.length();
    std::vector<int> result;
    if (m == 0 || n == 0) {
        return result;
    }
    std::vector<int> border =
        is_standart_or_advanced ? findPrefixFunction(substr, count) : findBorderFunction(substr, count);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        count += 2;
        bool is_str_i_m_one_subst = str[-1 + i] == '?';
        bool is_substr_k_subst = substr[k] == '?';
        if (!is_str_i_m_one_subst && !is_substr_k_subst) {
            while (k > 0 && substr[k] != str[-1 + i]) {
                ++count;
                k = border[-1 + k];

                if (k > 0 && substr[k] == '?') {
                    is_substr_k_subst = true;
                    break;
                }
                ++count;
            }
            ++count;
        }

        if (is_str_i_m_one_subst || is_substr_k_subst) {
            ++k;
        } else {
            ++count;
            if (substr[k] == str[-1 + i]) {
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
