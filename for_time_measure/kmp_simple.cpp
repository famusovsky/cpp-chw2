#include <iostream>
#include <vector>
#include <string>
#include "string_processing/functions.h"

std::vector<int> knuthMorrisPratt(const std::string& str, const std::string& substr) {
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
