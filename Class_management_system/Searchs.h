#pragma once
#include"Message.h"
#include <vector>
class Searchs
{
public:
	static void MenuSearch();
	static bool NameSearch(Message message, std::string x);
	static bool IdSearch(Message message, std::string x);
	static bool WageSearch(Message message, std::string x);
	static bool Similarity(Message message, std::string x);
};

