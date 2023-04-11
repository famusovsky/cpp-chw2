#include <vector>
#include <string>
#include "string_processing/functions.h"
#include "algorithms.h"

std::vector<int> with_substitutions::knuthMorrisPrattAdvanced(const std::string& str,
                                                              const std::string& substr,
                                                              int64_t& count) {
    return with_substitutions::kMP(str, substr, count, false);
}
