#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<string>
#include "Searchs.h"

void Searchs::MenuSearch()
{
	system("cls");
	std::cout << Prints::Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Prints::Blank(5) << "  Vector-List-System-Search" << std::endl;
	std::cout << Prints::Blank(6) << "1、姓名查找" << std::endl;
	std::cout << Prints::Blank(6) << "2、编号查找" << std::endl;
	std::cout << Prints::Blank(6) << "3、工资段查找" << std::endl;
	std::cout << Prints::Blank(6) << "4、模糊查找" << std::endl;
	std::cout << Prints::Blank(6) << "5、返回菜单" << std::endl;
	std::cout << Prints::Blank(5) << ">---------------------------<" << std::endl << Prints::Blank(6) << "请选择:";
}

bool Searchs::NameSearch(Message message, std::string x)
{
	return message.name == x;
}

bool Searchs::IdSearch(Message message, std::string x)
{
	int xx = atoi(x.c_str());
	return message.id == xx;
}

bool Searchs::WageSearch(Message message, std::string x)
{
	std::stringstream ss(x);//字符串流
	std::string s1, s2;
	std::getline(ss, s1, ',');
	std::getline(ss, s2);
	double xx1 = atof(s1.c_str());
	double xx2 = atof(s2.c_str());
	double temp,EPS = 1e-6;
	if (xx1 - xx2 > EPS)
	{
		temp = xx1;
		xx1 = xx2;
		xx2 = temp;
	}
	double wages = atof(message.wage.c_str());
	return (wages + EPS > xx1)&&(wages + EPS < xx2);
}

bool Searchs::Similarity(Message message, std::string x)
{
	const char* names = message.name.c_str();
	char ids[20];
	sprintf(ids, "%d", message.id);
	const char* wages = message.wage.c_str();
	const char* xx = x.c_str();
	return strstr(names, xx) || strstr(ids, xx) || strstr(wages, xx);
}
