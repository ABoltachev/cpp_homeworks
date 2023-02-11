#include <iostream>
#include "algorithms.hpp"
using namespace std;

int main() 
{
	algo::vector<int> a = {8, 2, 0, 5, 4, 1};
	algo::sort(a);
	for (auto i : algo::range(a.size()))
		cout << a[i];
	return 0;
}