// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include "../checker/functions.h"

void runTimeToFile(
    std::vector<std::vector<int> (*)(const std::string &, const std::string &)> functions,
    std::vector<std::string> names, std::vector<std::string> pathes, std::fstream &file, bool with_substitutions) {
    std::regex pattern("([^/]+)(?=\\.txt$)");
    for (size_t i = 0; i < functions.size(); ++i) {
        for (size_t j = 0; j < pathes.size(); ++j) {
            std::smatch match;
            file << (std::regex_search(pathes[j], match, pattern) ? match.str() + " - " : "") <<  names[i];
            std::vector<int> (*func)(const std::string &, const std::string &) = functions[i];
            std::vector<std::vector<int64_t>> times = timer(func, with_substitutions, pathes[j]);
            for (size_t z = 0; z < times.size(); ++z) {
                double average = 0;
                for (size_t k = 0; k < times[z].size(); ++k) {
                    average += times[z][k];
                }
                average /= static_cast<double>(times[z].size());
                file << ";" << average;
            }
            file << std::endl;
        }
    }
    file.close();
}
