#include "stllib/set.hpp"
#include "stllib/array.hpp"
#include "stllib/vector.hpp"
#include <iostream>

int main()
{
    // Set
    hw::set<int> set{-10,90,45,1,3};
    set.insert(1);
    set.insert(10);
    set.insert(4);
    set.insert(-2);
    for(auto el : set)
    {
        std::cout << el << '\n';
    }
    if(not set.empty())
        set.clear();
    for(auto el : set)
    {
        std::cout << el << '\n';
    }
    set.insert(1);
    set.insert(10);
    set.insert(4);
    set.insert(-2);
    if(set.find(4) != set.end())
        std::cout << "True" << '\n';
    
    // Array
    std::cout << "+++++++Array++++++++" << '\n';
    hw::array<long,10> a1 = {1,2,3,4,4,5,6,7,8,9};
    hw::array<long,0> a2;
    for(auto el : a1)
        std::cout << el << '\n';
    std::cout << (a2.empty() ? "Empty" : "Filled") << '\n';
    a1[3] = 100;
    for(auto el : a1)
        std::cout << el << '\n';

    // Vector
    std::cout << "+++++++Vector++++++" << '\n';
    hw::vector<long> vec1 = { 1, 2,3,4,5,6,7,7,5};
    hw::vector<long> vec2;
    for(int i(0); i < 20; ++i)
        vec2.push_back(i);
    vec2.resize(50,66);
    for(int i(0); i < vec1.size(); ++i)
        std::cout << vec1[i] << '\n';
    for(int i(0); i < vec2.size(); ++i)
        std::cout << vec2[i] << '\n';
    vec1.clear();
    for(int i(0); i < vec1.size(); ++i)
        std::cout << vec1[i] << '\n';
    vec1.push_back(111);
    vec2 = vec1;
    for(int i(0); i < vec2.size(); ++i)
        std::cout << vec2[i] << '\n';

    return 0;
}