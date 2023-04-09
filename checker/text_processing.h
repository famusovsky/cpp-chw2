#include <string>

const int MAX_SUBSTR_SIZE = 3000;
const int STEP = 100;

/// Функция, которая возвращает текст из файла
/// \param путь к файлу
/// \return текст из файла
std::string getText(const std::string& path);