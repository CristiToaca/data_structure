#include <iostream>
#include "DynamicArray.h"
#include <vector>


using namespace ct::data_structure;

void TestArray();

void main()
{
	TestArray();
}


void TestArray()
{
	DynamicArray<int> array;

	for (int i = 0; i < 5400; ++i)
	{
		array.PushBack(i);
		std::cout << "i: " << array.Get(i) << " " << "size: " << array.size() << " " << "capacity: " << array.capacity();
		if (i % 4 == 0)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << "  |  ";
		}
	}
	std::cout << std::endl;
}