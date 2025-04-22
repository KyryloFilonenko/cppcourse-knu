#include "OrderedVector.hpp"
#include "Complex.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ranges>

struct ReverseStringLess {
    bool operator() (const std::string &s, const std::string &t) const {
        // TODO: compare reversed strings
        std::string ra = s, rb = t;
        std::reverse(ra.begin(), ra.end());
        std::reverse(rb.begin(), rb.end());
        return ra < rb;
    }
};

struct ManhattanLess {
    bool operator()(const Complex& a, const Complex& b) const {
        return (std::abs(a.real()) + std::abs(a.imaginary())) <
               (std::abs(b.real()) + std::abs(b.imaginary()));
    }
};

int main() {
    std::cout << "Integer\n";
    OrderedVector<int> v(10);
    for (int i = 10; i > 0; i--)
        v.add(i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string> vs(5);
    vs.add(std::string("one"));
    vs.add(std::string("two"));
    vs.add(std::string("three"));
    vs.add(std::string("four"));
    vs.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs[i] << " ";
    std::cout << "\n\n";

    // TODO: Demonstrate OrderedVector with Complex as element type similar to above
    std::cout << "Complex\n";
    OrderedVector<Complex> vc(5);
    vc.add(Complex(1, 2));
    vc.add(Complex(3, 4));
    vc.add(Complex(0.5, 1.5));
    vc.add(Complex(2, 1));
    vc.add(Complex(1, 1));
    for (int i = 0; i < 5; i++)
        std::cout << vc[i] << " ";
    std::cout << "\n\n";


    // TODO: Extend OrderedVector to allow to customize the ordering via an additional template paramter.
    //       Then, demonstrate the new functionality by ordering an OrderedVector<std::string>,
    //       where the strings are compared starting at their last letters.
    std::cout << "Reverse string order\n";
    OrderedVector<std::string, ReverseStringLess> revVec(5);
    revVec.add("one");
    revVec.add("two");
    revVec.add("three");
    revVec.add("four");
    revVec.add("five");
    for (int i = 0; i < 5; i++)
        std::cout << revVec[i] << " ";
    std::cout << "\n\n";

    // TODO: Order an OrderedVector of Complex based on the Manhattan distance
    std::cout << "Complex ordered by Manhattan distance\n";
    OrderedVector<Complex, ManhattanLess> manhattanVec(5);
    manhattanVec.add(Complex(3, 4));
    manhattanVec.add(Complex(1, -1));
    manhattanVec.add(Complex(0, 0));
    manhattanVec.add(Complex(-2, 3));
    manhattanVec.add(Complex(1, 1));
    for (int i = 0; i < 5; i++)
        std::cout << manhattanVec[i] << " ";
    std::cout << "\n\n";


}
