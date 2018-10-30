#pragma once
#include <string>
#include <vector>

class StringPractice
{
public:
	StringPractice();
	~StringPractice();


	static bool CheckPermutation(const std::string& a, const std::string& b);

	static void URLify(std::string& string, int size);

	static bool PalindromePermutation(const std::string& input);

	static bool OneAway(const std::string& first, const std::string& second);

	static std::string StringCompression(const std::string& input);

	static void RotateMatrix(std::vector<std::vector<bool>>& matrix);

	static void PrintMatrix(const std::vector<std::vector<bool>>& matrix);

	static void Print1024Matrix(const std::vector<std::vector<int>>& matrix);

	static std::vector<std::vector<int>> StartGame1024();
	static bool MoveUpGame1024(std::vector<std::vector<int>>& map);
	static bool MoveLeftGame1024(std::vector<std::vector<int>>& map);
	static bool MoveDownGame1024(std::vector<std::vector<int>>& map);
	static bool MoveRightGame1024(std::vector<std::vector<int>>& map);

	static bool CheckGameOver(std::vector<std::vector<int>> map);
	static void AddNewTile(std::vector<std::vector<int>>& map);

};

