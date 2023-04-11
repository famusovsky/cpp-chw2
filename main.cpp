// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <fstream>
#include <string>
#include <vector>
#include "for_time_measure/normal/algorithms.h"
#include "for_time_measure/with_substitution/algorithms.h"
#include "for_comp_count_measure/normal/algorithms.h"
#include "for_comp_count_measure/with_substitution/algorithms.h"
#include "checker/functions.h"
#include "task_execution/functions.h"

int main() {
    std::vector<std::vector<int> (*)(const std::string &, const std::string &)>
        normal_time_functions = {&normal::knuthMorrisPrattStandart, 
                                 &normal::knuthMorrisPrattAdvanced,
                                 &normal::naiveAlgorithm};
    std::vector<std::vector<int> (*)(const std::string &, const std::string &, int64_t &)>
        normal_comp_counts_functions = {&normal::knuthMorrisPrattStandart,
                                        &normal::knuthMorrisPrattAdvanced, 
                                        &normal::naiveAlgorithm};
    std::vector<std::vector<int> (*)(const std::string &, const std::string &)>
        subst_time_functions = {&with_substitutions::knuthMorrisPrattStandart,
                                &with_substitutions::knuthMorrisPrattAdvanced,
                                &with_substitutions::naiveAlgorithm};
    std::vector<std::vector<int> (*)(const std::string &, const std::string &, int64_t &)>
        subst_comp_counts_functions = {&with_substitutions::knuthMorrisPrattStandart,
                                       &with_substitutions::knuthMorrisPrattAdvanced,
                                       &with_substitutions::naiveAlgorithm};

    std::vector<std::string> names = {"knuthMorrisPratt", 
                                      "knuthMorrisPrattAdvanced",
                                      "naiveAlgorithm"};

    std::vector<std::string> input_pathes = {
        "../data/texts/bin_text_10000.txt", "../data/texts/bin_text_100000.txt",
        "../data/texts/quad_text_10000.txt", "../data/texts/quad_text_100000.txt"};

    std::fstream file;

    file = createFile("../data/output/time_normal.csv");
    runTimeToFile(normal_time_functions, names, input_pathes, file, false);
    file.close();

    file = createFile("../data/output/comp_count_normal.csv");
    runComparisonsToFile(normal_comp_counts_functions, names, input_pathes, file, false);
    file.close();

    file = createFile("../data/output/time_with_subst.csv");
    runTimeToFile(subst_time_functions, names, input_pathes, file, true);
    file.close();

    file = createFile("../data/output/comp_count_with_subst.csv");
    runComparisonsToFile(subst_comp_counts_functions, names, input_pathes, file, true);
    file.close();

    return 0;
}
