// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <cstdint>
#include <string>
#include <vector>

/// Метод, измеряющий время работы данных алгоритмов поиска вхождений подстроки в строку
/// \param func - функция, время работы которой нужно измерить
/// \param with_substitutions - нужно ли тестировать функцию подстроками с символами подстановки
/// \param path - путь к файлу, в котором хранится исходный текст
/// \return вектор, в котором хранятся вектора по 10 различных измерений времени работы алгоритма для каждого размера подстроки
std::vector<std::vector<int64_t>> timer(std::vector<int> (*func)(const std::string&, const std::string&), bool with_substitutions, std::string path);

/// Метод, измеряющий количество сравнений, которые выполняются данными алгоритмами поиска вхождений подстроки в строку
/// \param func - функция, количество сравнений в которой нужно измерить
/// \param with_substitutions - нужно ли тестировать функцию подстроками с символами подстановки
/// \param path - путь к файлу, в котором хранится исходный текст
/// \return вектор, в котором хранится количество сравнений для каждого размера подстроки
std::vector<int64_t> counter(std::vector<int> (*func)(const std::string&, const std::string&, int64_t&), bool with_substitutions, std::string path);
