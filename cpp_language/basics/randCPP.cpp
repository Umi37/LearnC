#include <iostream>
#include <cstdlib>

int main() {
    srand(1);
    for (int i = 0; i < 5; i++) {
        std::cout << rand() << std::endl;
    }
}

// 1804289383
// 846930886
// 1681692777
// 1714636915
// 1957747793