cmake_minimum_required(VERSION 3.16)

project(homeworks_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <random>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> left_aisle(n);
	vector<int> right_aisle(n);
	vector<int> left_window(n);
	vector<int> right_window(n);
	string row;
	for (int i = 0; i < n; ++i) 
	{
		cin >> row;
		int p = 0;
		while (row[p] != '_' && row[p] != '#') { ++p; }
		left_window[i] = p;
		if (p == 3)
			left_aisle[i] = 3;
		else if (p == 2)
			left_aisle[i] = 0;
		else if (p == 1) 
			left_aisle[i] = (row[2] == '.') ? 1 : 0;
		else {
			if (row[2] == '.')
				if (row[1] == '.')
					left_aisle[i] = 2;
				else
					left_aisle[i] = 1;
			else
				left_aisle[i] = 0;
		}
		p = 4;
		while (p < row.length() && row[p] != '#') { ++p; }
		right_aisle[i] = p;
		if (p == 7)
			right_window[i] = 3;
		else if (p == 6)
			right_window[i] = 0;
		else if (p == 5)
			right_window[i] = (row[4] == '.') ? 1 : 0;
		else {
			if (row[6] == '.')
				if (row[5] == '.')
					right_window[i] = 2;
				else
					right_window[i] = 1;
			else
				right_window[i] = 0;
		}
	}
	cin >> n;
	int num;
	string side, pos;
	for (int i = 0; i < n; ++i) 
	{
		cin >> num >> side >> pos;
		if (side == "left")
			if (pos == "aisle")
			{
				for (int i = 0; i < left_aisle.size(); ++i) 
				{
					if (left_aisle[i] >= num) 
					{
						left_aisle[i] = 0;
					}
				}
			}
	}
	return 0;
}