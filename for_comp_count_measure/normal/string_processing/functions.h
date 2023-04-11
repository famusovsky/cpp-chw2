// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <string>
#include <vector>

/// Метод, реализующий алгоритм вычисления префикс-функции
/// \param str - строка, для которой вычисляется префикс-функция
/// \param count - счетчик сравнений
/// \return вектор, в котором хранится префикс-функция
std::vector<int> findPrefixFunction(const std::string& str, int64_t& count);

/// Метод, реализующий алгоритм вычисления бордер-функции
/// \param str - строка, для которой вычисляется бордер-функция
/// \param count - счетчик сравнений
/// \return вектор, в котором хранится бордер-функция
std::vector<int> findBorderFunction(const std::string& str, int64_t& count);
