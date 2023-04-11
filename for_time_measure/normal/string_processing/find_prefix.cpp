// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <vector>
#include <string>

std::vector<int> findPrefixFunction(const std::string& str) {
    int n = str.length();
    std::vector<int> pi(n);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < n; ++i) {
        while (k > 0 && str[k] != str[i]) {
            k = pi[k - 1];
        }
        if (str[k] == str[i]) {
            k++;
        }
        pi[i] = k;
    }
    return pi;
}