#include "../include/solution.h"
#include <string>

std::string solution(const std::string& line) {
    std::string result = line;  // создаем копию строки
    for (char& c : result) {    // проходим по ссылке на каждый символ
        if (c == 'a') {
            c = 'b';
        } else if (c == 'b') {
            c = 'a';
        }
    }
    return result;
}
