#include <iostream>
#include "include/solution.h"
#include <string>



int main() {
    std::string line;
    std::cin >> line;
    std::string result = solution(line);
    std::cout << result;
    return 0;
}