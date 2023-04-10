#include <string>

std::string addSubstitutions(const std::string& str) {
    std::string result = str;
    srand(std::time(nullptr));
    int substs_cnt = rand() % 4 + 1;
    // XXX: im not sure that this works
    for (int i = 0; i < substs_cnt; ++i) {
        result[rand() % result.size()] = '?';
    }

    return result;
}