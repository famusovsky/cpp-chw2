#include <vector>
#include <string>

std::vector<int> findPrefixFunction(const std::string& str, int64_t& count) {
    int n = str.length();
    std::vector<int> pi(n);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < n; ++i) {
        while (k > 0 && str[k] != str[i]) {
            k = pi[k - 1];
            ++count;
        }
        ++count;
        if (str[k] == str[i]) {
            k++;
        }
        ++count;
        pi[i] = k;
    }
    return pi;
}