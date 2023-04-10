#include <vector>
#include <string>

std::vector<int> findPrefixFunction(const std::string& str, int64_t& count) {
    int n = str.length();
    std::vector<int> pi(n);
    pi[0] = 0;
    int k = 0;
    // TODO: make normal counting -- you should not do 2 comparisons in the while loop everytime
    for (int i = 1; i < n; ++i) {
        bool is_str_i_subst = str[i] != '?';
        ++count;
        if (!is_str_i_subst) {
            while (k > 0 && str[k] != str[i] && str[k] != '?') {
                k = pi[k - 1];
                count += 2;
            }
            count += 2;
        }
        // TODO: make normal counting
        if (is_str_i_subst) {
            ++k;
        } else {
            if (str[k] == str[i] || str[k] == '?') {
                ++k;
            }
            count += 2;
        }
        pi[i] = k;
    }
    return pi;
}