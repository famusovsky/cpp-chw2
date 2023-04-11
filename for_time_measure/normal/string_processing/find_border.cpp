// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <vector>
#include <string>
#include "functions.h"

std::vector<int> findBorderFunction(const std::string& str) {
    int n = str.length();
    std::vector<int> pi = findPrefixFunction(str);
    std::vector<int> border(n);
    border[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (str[pi[i]] != str[i + 1]) {
            border[i] = pi[i];
        } else {
            border[i] = border[pi[i]];
        }
    }
    return border;
}