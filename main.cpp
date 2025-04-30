#include <iostream>
#include "RNGs.h"

using namespace std;

void printVector(const std::vector<double>& ans) {
    for (double value : ans) {
        std::cout << value << std::endl;
    }
}



int main() {
    RNGs rng;
    std::vector<double> random_numbers = rng.MSM(1234,10);
    printVector(random_numbers);
    return 0;
}
