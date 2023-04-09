#include <string>
#include <fstream>

std::fstream createFile(const std::string& path) {
    std::fstream file;
    file.open(path, std::ios::out);
    file.precision(2);
    file << std::fixed;
    return file;
}
