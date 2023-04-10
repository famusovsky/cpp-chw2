// 
// Степанов А, БПИ212

#include <string>
#include <vector>

/// Метод, реализующий алгоритм вычисления префикс-функции
/// \param str - строка, для которой вычисляется префикс-функция
/// \return вектор, в котором хранится префикс-функция
std::vector<int> findPrefixFunction(const std::string& str);

/// Метод, реализующий алгоритм вычисления бордер-функции
/// \param str - строка, для которой вычисляется бордер-функция
/// \return вектор, в котором хранится бордер-функция
std::vector<int> findBorderFunction(const std::string& str);
