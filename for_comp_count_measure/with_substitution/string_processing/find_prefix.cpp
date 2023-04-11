#include <vector>
#include <string>

std::vector<int> findPrefixFunction(const std::string& str, int64_t& count) {
    int n = str.length();
    std::vector<int> pi(n);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < n; ++i) {
        count += 2;
        bool is_str_i_subst = str[i] == '?';
        bool is_str_k_subst = str[k] == '?';

        if (!is_str_i_subst && !is_str_k_subst) {
            while (k > 0 && str[k] != str[i]) {
                ++count;
                k = pi[k - 1];

                if (k > 0 && str[k] == '?') {
                    is_str_k_subst = true;
                    break;
                }
                ++count;
            }
            ++count;
        }

        if (is_str_i_subst || is_str_k_subst) {
            ++k;
        } else {
            ++count;
            if (str[k] == str[i]) {
                ++k;
            }
        }
        pi[i] = k;
    }
    return pi;
}
