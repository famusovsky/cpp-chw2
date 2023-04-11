// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <string>

std::string addSubstitutions(const std::string& str) {
    std::string result = str;
    srand(std::time(nullptr));
    int substs_cnt = rand() % 4 + 1;
    for (int i = 0; i < substs_cnt; ++i) {
        result[rand() % result.size()] = '?';
    }

    return result;
}