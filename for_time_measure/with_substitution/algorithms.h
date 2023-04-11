// 
// Степанов А, БПИ212

#include <vector>
#include <string>

namespace with_substitutions {

/// Метод, реализующий алгоритм Кнута-Морриса-Пратта c использованием стандартных либо уточнённых граней
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \param is_standart_or_advanced - флаг, указывающий на то, нужно ли использовать стандартные грани или уточнённые
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> kMP(const std::string& str, const std::string& substr,
                                         bool is_standart_or_advanced);

/// Метод, вызывающий алгоритм Кнута-Морриса-Пратта c использованием уточненных граней
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> knuthMorrisPrattAdvanced(const std::string& str, const std::string& substr);

/// Метод, вызывающий алгоритм Кнута-Морриса-Пратта c использованием стандартных граней
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> knuthMorrisPrattStandart(const std::string& str, const std::string& substr);

/// Метод, реализующий наивный алгоритм с использованием простого посимвольного сравнения
/// \param str - строка, в которой ищем подстроку
/// \param substr - подстрока, которую ищем в строке
/// \return вектор, в котором хранятся индексы начала вхождений подстроки в строку
std::vector<int> naiveAlgorithm(const std::string& str, const std::string& substr);

}
