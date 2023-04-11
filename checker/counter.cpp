// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <cstdlib>
#include <vector>
#include <string>
#include "funcs_for_checker.h"

std::vector<int64_t> counter(std::vector<int> (*func)(const std::string&, const std::string&, int64_t&),
                             bool with_substitution, std::string path) {
    std::string input_text = getText(path);
    int upper_border = input_text.size() - MAX_SUBSTR_SIZE;
    std::vector<int64_t> counts(MAX_SUBSTR_SIZE / STEP);
    for (int n = STEP; n <= MAX_SUBSTR_SIZE; n += STEP) {
        int64_t count = 0;
        srand(std::time(nullptr));
        std::string sub = input_text.substr(rand() % upper_border, n);
        if (with_substitution) {
            sub = addSubstitutions(sub);
        }
        func(input_text, sub, count);
        counts[(n - STEP) / STEP] = count;
    }
    return counts;
}