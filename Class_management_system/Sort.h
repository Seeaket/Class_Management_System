#pragma once
#include<vector>
#include"Message.h"
class Sort
{
public:
	static void MenuSort();
	static bool NameSort(std::vector<Message> vec, int j, int i);
	static bool IdSort(std::vector<Message> vec, int j, int i);
	static bool WageSort(std::vector<Message> vec, int j, int i);
};

