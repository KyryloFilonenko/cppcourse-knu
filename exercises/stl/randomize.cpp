#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    std::generate(v.begin(), v.end(), [n = 0, initial, step]() mutable {
        return initial + step * n++;
    });
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(v.begin(), v.end(), gen);

    // compute differences
    std::adjacent_difference(v.begin(), v.end(), diffs.begin());
    diffs.erase(diffs.begin());

    // compute standard deviation of all differences
    T sum = std::accumulate(diffs.begin(), diffs.end(), T{});
    T sumsq = std::accumulate(diffs.begin(), diffs.end(), T{}, [](T acc, T val) {
        return acc + val * val;
    });
    T mean = sum / static_cast<double>(len);
    T variance = sumsq / static_cast<double>(len) - mean * mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    std::cout << "=== DOUBLE ===\n";
    compute(100, 0.0, 7.0);
    // call compute here with Complex
    std::cout << "=== COMPLEX ===\n";
    compute(100, Complex(0, 0), Complex(7, 0));
}
