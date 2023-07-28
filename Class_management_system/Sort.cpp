#include<iostream>
#include "Sort.h"

void Sort::MenuSort()
{
	system("cls");
	std::cout << Prints::Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Prints::Blank(5) << "   Vector-List-System-Sort" << std::endl;
	std::cout << Prints::Blank(6) << "1¡¢ÐÕÃûÅÅÐò" << std::endl;
	std::cout << Prints::Blank(6) << "2¡¢±àºÅÅÅÐò" << std::endl;
	std::cout << Prints::Blank(6) << "3¡¢¹¤×ÊÅÅÐò" << std::endl;
	std::cout << Prints::Blank(6) << "4¡¢·µ»Ø²Ëµ¥" << std::endl;
	std::cout << Prints::Blank(5) << ">---------------------------<" << std::endl << Prints::Blank(6) << "ÇëÑ¡Ôñ:";
}

bool Sort::NameSort(std::vector<Message> vec,int j,int i)
{
	return vec.at(j).name > vec.at(i).name;
}

bool Sort::IdSort(std::vector<Message> vec, int j, int i)
{
	return vec.at(j).id > vec.at(i).id;
}

bool Sort::WageSort(std::vector<Message> vec, int j, int i)
{
	double s1 = atof(vec.at(j).wage.c_str());
	double s2 = atof(vec.at(i).wage.c_str());
	const double EPS = 1e-6;
	return (s1 - s2) > EPS;
}
