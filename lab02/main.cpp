#include <iostream>
#include "include/solution.h"

int main() {
    int n, m;
    std::cout << "Введите размеры шоколадки (n x m): ";
    std::cin >> n >> m;

    int result = minimalCuts(n, m);
    std::cout << "Минимальное количество разбиений: " << result << std::endl;

    return 0;
}
