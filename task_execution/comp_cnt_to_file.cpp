#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include "../checker/functions.h"

void runComparisonsToFile(
    std::vector<std::vector<int> (*)(const std::string &, const std::string &, int64_t &)>
        functions,
    std::vector<std::string> names, std::vector<std::string> pathes, std::fstream &file) {
    std::regex pattern("/([^/]+)\\.txt$");
    for (size_t i = 0; i < functions.size(); ++i) {
        for (size_t j = 0; j < pathes.size(); ++j) {
            std::smatch match;
            file << names[i]
                 << (std::regex_search(pathes[j], match, pattern) ? " - " + match.str() : "");
            std::vector<int> (*func)(const std::string &, const std::string &, int64_t &) =
                functions[i];
            std::vector<int64_t> counts = counter(func, pathes[j]);
            for (size_t z = 0; z < counts.size(); ++z) {
                file << ";" << counts[z];
            }
            file << std::endl;
        }
    }
    file.close();
}
