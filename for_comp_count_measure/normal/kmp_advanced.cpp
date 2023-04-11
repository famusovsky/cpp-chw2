// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> normal::knuthMorrisPrattAdvanced(const std::string& str, const std::string& substr, int64_t& count) {
    return normal::kMP(str, substr, count, false);
}
