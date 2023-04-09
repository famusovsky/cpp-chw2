// 
// Степанов А, БПИ212

// XXX: #ifndef CHW2__ALGORITHMS_WITH_COMP_COUNTS_H_
// XXX: #define CHW2__ALGORITHMS_WITH_COMP_COUNTS_H_
#include <vector>
#include <string>

/// Метод, реализующий алгоритм Кнута-Морриса-Пратта c использованием уточненных граней и подсчитывающий количество сравнений
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \param count - количество сравнений
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> knuthMorrisPrattAdvanced(const std::string& str, const std::string& substr, int64_t& count);

/// Метод, реализующий алгоритм Кнута-Морриса-Пратта c использованием стандартных граней и подсчитывающий количество сравнений
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \param count - количество сравнений
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> knuthMorrisPratt(const std::string& str, const std::string& substr, int64_t& count);

/// Метод, реализующий наивный алгоритм с использованием простого посимвольного сравнения и подсчитывающий количество сравнений
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \param count - количество сравнений
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> naiveAlgorithm(const std::string& str, const std::string& substr, int64_t& count);

// XXX: #endif
