//
// Степанов А, БПИ212

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "for_time_measure/algorithms.h"
#include "for_comp_count_measure/algorithms.h"
#include "checker/functions.h"
#include "task_execution/functions.h"

int main() {
    std::vector<std::vector<int> (*)(const std::string &, const std::string &)> normal_functions = {
        &knuthMorrisPratt, &knuthMorrisPrattAdvanced, &naiveAlgorithm};
    std::vector<std::vector<int> (*)(const std::string &, const std::string &, int64_t &)>
        comp_counts_functions = {&knuthMorrisPratt, &knuthMorrisPrattAdvanced, &naiveAlgorithm};
    std::vector<std::string> names = {"knuthMorrisPratt", "knuthMorrisPrattAdvanced",
                                      "naiveAlgorithm"};

    std::vector<std::string> input_pathes = {
        "../data/texts/bin_text_10000.txt", "../data/texts/bin_text_100000.txt",
        "../data/texts/quad_text_10000.txt", "../data/texts/quad_text_100000.txt"};

    std::fstream file;

    file = createFile("../data/output/time.csv");
    runTimeToFile(normal_functions, names, input_pathes, file);

    file = createFile("../data/output/comp_count.csv");
    runComparisonsToFile(comp_counts_functions, names, input_pathes, file);

    return 0;
}
