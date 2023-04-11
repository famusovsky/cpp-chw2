// АиСД-2, 2023, КДЗ-2
// Степанов А, БПИ212

#include <string>

const int MAX_SUBSTR_SIZE = 3000;
const int STEP = 100;

/// Функция, которая возвращает текст из файла
/// \param путь к файлу
/// \return текст из файла
std::string getText(const std::string& path);

/// Функция, добавляющая знаки подстановки в строку
/// \param входная строка
/// \return строка, с добавленными в неё знаками подстановки
std::string addSubstitutions(const std::string& str);