#include <fstream>
#include <string>

std::string getText(const std::string& path) {
    std::fstream file;
    file.open(path, std::ios::in);
    std::string result;
    std::string line;
    while (getline(file, line)) {
        result += line + '\n';
    }
    file.close();
    return result;
}