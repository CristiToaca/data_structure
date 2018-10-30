#include "StringPractice.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <math.h>


StringPractice::StringPractice()
{
}


StringPractice::~StringPractice()
{
}

void SortString(std::string& string);

bool StringPractice::CheckPermutation(const std::string& firstString, const std::string& secondString)
{
	if (firstString.size() != secondString.size())
		return false;

	std::vector<int> charList(128);

	for (int i = 0; i < firstString.size(); ++i)
	{
		charList[int(firstString[i])]++;
		charList[int(secondString[i])]--;
	}

	for (int i = 0; i < charList.size(); ++i)
	{
		if (charList[i] != 0)
			return false;
	}

	return true;
}

void StringPractice::URLify(std::string& string, int size)
{
	int realSize = string.size();

	//Input: "Mr John Smith ", 13 
	//Output: "Mr%20John%20Smith"
	for (int i = size - 1; i >= 0; --i)
	{
		if (string[i] == ' ')
		{
			string[--realSize] = '0';
			string[--realSize] = '2';
			string[--realSize] = '%';			
		}
		else
		{
			string[realSize - 1] = string[i];

			--realSize;
		}
	}
}

bool StringPractice::PalindromePermutation(const std::string& input)
{
	if (input.size() < 2)
		return true;

	std::vector<int> charList(60);

	bool justOneOddLetter = false;

	for (size_t i = 0; i < input.size(); ++i)
	{
		if (input[i] != ' ')
			++charList[(input[i] - 'A')];
	}

	for (size_t i = 0; i < charList.size(); i++)
	{
		if (charList[i] % 2 != 0)
		{
			if (!justOneOddLetter)
				justOneOddLetter = true;
			else
				return false;
		}
	}

	return true;
}

bool StringPractice::OneAway(const std::string& first, const std::string& second)
{
	int sizeDifference = first.size() - second.size();
	if (abs(sizeDifference) > 1)
		return false;

	bool allowOneMistake = true;

	int i = 0;
	int j = 0;

	for (; i < first.size() && j < second.size();)
	{
		if (first[i] != second[j])
		{
			if (allowOneMistake)
			{
				if ((j+1 < second.size()) && first[i] == second[j + 1])
					++j;
				else if ((i + 1 < first.size()) && first[i + 1] == second[j])
					++i;


				allowOneMistake = false;
			}
			else
				return false;
		}

		++i;
		++j;
	}

	return true;
}

std::string StringPractice::StringCompression(const std::string& input)
{
	std::string compressed;

	int count = 0;
	char element = input[0];

	for (size_t i = 0; i < input.size(); i++)
	{
		if (element == input[i])
			count++;
		else
		{
			compressed.append(1, element);
			compressed.append(std::to_string(count));
			element = input[i];
			count = 1;
		}
	}

	compressed.append(1, element);
	compressed.append(std::to_string(count));

	if (compressed.size() >= input.size())
		return input;
	else
		return compressed;

}

void StringPractice::RotateMatrix(std::vector<std::vector<bool>>& matrix)
{
	int size = matrix.size();

	for (size_t i = 0; i < size / 2; i++)
	{
		for (int j = i; j < size - 1 - i; ++j)
		{
			int is = size - i - 1;
			int js = size - j - 1;
			bool temp1 = matrix[i][j];
			bool temp2 = matrix[j][is];
			bool temp3 = matrix[is][js];
			bool temp4 = matrix[js][i];

			matrix[i][j] = temp4;
			//PrintMatrix(matrix);
			matrix[j][is] = temp1;
			//PrintMatrix(matrix);
			matrix[is][js] = temp2;
			//PrintMatrix(matrix);
			matrix[js][i] = temp3;
			//PrintMatrix(matrix);

			//PrintMatrix(matrix);

		}	

		//PrintMatrix(matrix);
	}
}

void StringPractice::PrintMatrix(const std::vector<std::vector<bool>>& matrix)
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void StringPractice::Print1024Matrix(const std::vector<std::vector<int>>& matrix)
{
	system("CLS");
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

std::vector<std::vector<int>> StringPractice::StartGame1024()
{
	srand(time(NULL));
	auto i = rand() % 4;
	auto j = rand() % 4;

	auto newTile = (rand() % 2 + 1) * 2;

	std::vector<std::vector<int>> map = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

	map[i][j] = newTile;

	return map;
}

bool StringPractice::CheckGameOver(std::vector<std::vector<int>> map)
{
	const int size = 4;

	int countZero = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j] == 0)
				++countZero;
		}
	}

	if (countZero != 0)
		return true;
	
	//check if we have possible compression
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (map[i][j] == map[i + 1][j])
			{
				//Compress Exist
				return true;
			}

//todo 
		}
	}

	return false;
}

void StringPractice::AddNewTile(std::vector<std::vector<int>>& map)
{
	//StringPractice::Print1024Matrix(map);

	const int size = 4;
	int countZero = 0;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j] == 0)
				++countZero;
		}
	}

	auto newTile = (rand() % 2 + 1) * 2;
	auto newTilePosition = rand() % countZero;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j] == 0)
			{
				--countZero;

				if (newTilePosition == countZero)
					map[i][j] = newTile;				
			}
		}
	}
}

bool StringPractice::MoveUpGame1024(std::vector<std::vector<int>>& map)
{
	const int size = 4;
	bool noMove = true;

	for (int j = 0; j < size; ++j)
	{	
		//move
		int is = 0;
		for (int i = 0; i < size; i++)
		{
			if (map[i][j] != 0)
			{
				if (is != i)
				{
					map[is][j] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				++is;
			}
		}

		//compress
		for (int i = 0; i < size - 1; ++i)
		{
			if (map[i][j] == map[i + 1][j])
			{
				map[i][j] *= 2;
				map[i + 1][j] = 0;
			}
		}	

		//move
		is = 0;
		for (int i = 0; i < size; i++)
		{
			if (map[i][j] != 0)
			{
				if (is != i)
				{
					map[is][j] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				++is;
			}
		}

	}

	if (noMove)//we have no move, so we just return without adding new tile
		return true;

	//add new tile	
	AddNewTile(map);
	return CheckGameOver(map);
}

bool StringPractice::MoveLeftGame1024(std::vector<std::vector<int>>& map)
{
	const int size = 4;
	bool noMove = true;

	for (int i = 0; i < size; ++i)
	{
		//move
		int js = 0;
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] != 0)
			{
				if (js != j)
				{
					map[i][js] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				++js;
			}
		}

		//compress
		for (int j = 0; j < size - 1; ++j)
		{
			if (map[i][j] == map[i][j + 1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
			}
		}

		//move
		js = 0;
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] != 0)
			{
				if (js != j)
				{
					map[i][js] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				++js;
			}
		}

	}

	if (noMove)//we have no move, so we just return without adding new tile
		return true;

	//add new tile	
	AddNewTile(map);
	return CheckGameOver(map);
}

bool StringPractice::MoveDownGame1024(std::vector<std::vector<int>>& map)
{
	const int size = 4;
	bool noMove = true;

	for (int j = 0; j < size; ++j)
	{
		//move
		int is = size - 1;
		for (int i = size - 1; i >= 0; --i)
		{
			if (map[i][j] != 0)
			{
				if (is != i)
				{
					map[is][j] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				--is;
			}
		}

		//compres
		for (int i = 0; i < size - 1; ++i)
		{
			if (map[i][j] == map[i + 1][j])
			{
				map[i][j] *= 2;
				map[i + 1][j] = 0;
			}
		}

		//move
		is = size - 1;
		for (int i = size - 1; i >= 0; --i)
		{
			if (map[i][j] != 0)
			{
				if (is != i)
				{
					map[is][j] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				--is;
			}
		}
	}

	if (noMove)//we have no move, so we just return without adding new tile
		return true;

	//add new tile	
	AddNewTile(map);
	return CheckGameOver(map);
}

bool StringPractice::MoveRightGame1024(std::vector<std::vector<int>>& map)
{
	const int size = 4;
	bool noMove = true;

	for (int i = 0; i < size; ++i)
	{
		//move
		int js = size - 1;
		for (int j = size - 1; j >= 0; --j)
		{
			if (map[i][j] != 0)
			{
				if (js != j)
				{
					map[i][js] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				--js;
			}
		}

		//compress
		for (int j = 0; j < size - 1; ++j)
		{
			if (map[i][j] == map[i][j + 1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
			}
		}

		//move
		js = size - 1;
		for (int j = size - 1; j >= 0; --j)
		{
			if (map[i][j] != 0)
			{
				if (js != j)
				{
					map[i][js] = map[i][j];
					map[i][j] = 0;
					noMove = false;
				}
				--js;
			}
		}

	}

	if (noMove)//we have no move, so we just return without adding new tile
		return true;

	//add new tile	
	AddNewTile(map);
	return CheckGameOver(map);
}
