// 
// Степанов А, БПИ212

// XXX: #ifndef CHW2__ALGORITHMS_H_
// XXX: #define CHW2__ALGORITHMS_H_
#include <vector>
#include <string>

/// Метод, реализующий алгоритм Кнута-Морриса-Пратта c использованием уточненных граней
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> knuthMorrisPrattAdvanced(const std::string& str, const std::string& substr);

/// Метод, реализующий алгоритм Кнута-Морриса-Пратта c использованием стандартных граней
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> knuthMorrisPratt(const std::string& str, const std::string& substr);

/// Метод, реализующий наивный алгоритм с использованием простого посимвольного сравнения
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> naiveAlgorithm(const std::string& str, const std::string& substr);

// XXX: #endif
