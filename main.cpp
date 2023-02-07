#include <array>
#include <iostream>
#include <vector>

#include "containers/array.hpp"
#include "containers/vector.hpp"

int main()
{
    lib::Vector<int> vector(1, 12);

    vector.push_back(1);
    vector.push_back(1);
    vector.push_back(1);
    vector.clear();
    vector.resize(1);
    std::cout << "Hello, test!" << std::endl;
    return 0;
}
