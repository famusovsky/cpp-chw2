#include <vector>
#include <string>
#include <chrono>
#include "text_processing.h"

std::vector<std::vector<int64_t>> timer(std::vector<int> (*func)(const std::string&, const std::string&),
                                        std::string path) {
    std::string input_text = getText(path);
    int upper_border = input_text.size() - MAX_SUBSTR_SIZE;
    std::vector<std::vector<int64_t>> times(MAX_SUBSTR_SIZE / STEP, std::vector<int64_t>(10));
    for (int n = STEP; n <= MAX_SUBSTR_SIZE; n += STEP) {
        std::vector<int64_t> time(100);
        for (size_t i = 0; i < time.size(); i++) {
            srand(std::time(nullptr));
            std::string sub = input_text.substr(rand() % upper_border, n);
            auto start = std::chrono::high_resolution_clock::now();
            func(input_text, sub);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            int64_t nanoseconds =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            time[i] = nanoseconds;
        }
        times[(n - STEP) / STEP] = time;
    }
    return times;
}
