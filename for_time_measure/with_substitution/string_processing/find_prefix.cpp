#include <vector>
#include <string>

std::vector<int> findPrefixFunction(const std::string& str) {
    int n = str.length();
    std::vector<int> pi(n);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < n; ++i) {
        bool is_str_i_substr = str[i] == '?';
        bool is_str_k_substr = str[k] == '?';

        if (!is_str_i_substr && !is_str_k_substr) {
            while (k > 0 && str[k] != str[i]) {
                k = pi[k - 1];

                if (k > 0 && str[k] == '?') {
                    is_str_k_substr = true;
                    break;
                }
            }
        }

        if (is_str_i_substr || is_str_k_substr || str[k] == str[i]) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}
