// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> normal::knuthMorrisPratt(const std::string& str, const std::string& substr) {
    int n = str.length();
    int m = substr.length();
    std::vector<int> result;
    if (m == 0 || n == 0) {
        return result;
    }
    std::vector<int> border = findPrefixFunction(substr);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        while (k > 0 && substr[k] != str[-1 + i]) {
            k = border[-1 + k];
        }
        if (substr[k] == str[-1 + i]) {
            k++;
        }
        if (k == m) {
            result.push_back(i - m);
            k = border[-1 + k];
        }
    }
    return result;
}
