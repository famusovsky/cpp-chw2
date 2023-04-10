// 
// Степанов А, БПИ212

#include <vector>
#include <string>

namespace with_substitutions {

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

}
