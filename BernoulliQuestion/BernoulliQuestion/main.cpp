#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>

double func(int n) {
    double result = pow(0.5, n);
    return result;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    // give "true" result of the time
    // give "false" result of the time
    std::bernoulli_distribution d(func(4));

    std::map<bool, int> hist;
    for (int n = 0; n < 100000; ++n) {
        hist[d(gen)]++;
    }
    for (auto p : hist) {
        std::cout << std::boolalpha << std::setw(5) << p.first
            << ' ' << std::string(p.second / 1000, '*') << '\n';
    }
}