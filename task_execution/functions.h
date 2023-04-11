// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <vector>
#include <string>

/// Метод, измеряющий время работы данных алгоритмов поиска вхождений подстроки в строку и записывающий результаты в файл
/// \param functions - вектор функций, время работы которых нужно измерить
/// \param names - вектор имен функций
/// \param pathes - вектор путей к файлам, в которых хранится исходный текст
/// \param file - файл, в который нужно записать результаты
void runTimeToFile(
    std::vector<std::vector<int> (*)(const std::string &, const std::string &)> functions,
    std::vector<std::string> names, std::vector<std::string> pathes, std::fstream &file, bool with_substitutions);

/// Метод, измеряющий количество сравнений в данных алгоритмах поиска вхождений подстроки в строку и записывающий результаты в файл
/// \param functions - вектор функций, количество сравнений в которых нужно измерить
/// \param names - вектор имен функций
/// \param pathes - вектор путей к файлам, в которых хранится исходный текст
/// \param file - файл, в который нужно записать результаты
void runComparisonsToFile(
    std::vector<std::vector<int> (*)(const std::string &, const std::string &, int64_t &)> functions,
    std::vector<std::string> names, std::vector<std::string> pathes, std::fstream &file, bool with_substitutions);

/// Метод, создающий файл
/// \param path - путь к файлу
/// \return - созданный файл
std::fstream createFile(const std::string& path);