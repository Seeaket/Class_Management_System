#include<iostream>
#include<vector>
#include<fstream>
#include"Message.h"
#include<iomanip>
#include "Searchs.h"
#include"Sort.h"

void Funcs::SaveFile(std::vector<Message>vec)
{
	std::ofstream openfile("Class_System.csh");
	if (openfile.is_open())
	{
		for (auto messages : vec)
		{
			openfile << messages.name << std::endl << messages.id << std::endl << messages.wage << std::endl;
		}
	}
	openfile.close();
}

std::vector<Message> Funcs::Load(std::vector<Message>&vec,Message& messages)
{
	std::ifstream openfile("Class_System.csh");
	if (openfile.is_open())
	{
		while(openfile >> messages.name >> messages.id >>messages.wage)
		{
			vec.push_back(messages);
		}
	}
	openfile.close();
	return vec;
}

void Funcs::Exits(std::vector<Message>& vec,Message& messages)
{
	std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << "     是否确认退出系统?        y[Y]/n[N]" << std::endl << Blank(6) << "    请选择:";
	int num = Judge();
	if (num == 1)
	{
		vec.clear();
		vec.shrink_to_fit();
		exit(0);
	}
	std::cout << std::endl <<  Blank(6) << (num == 0 ? "   已取消退出!" : "无效操作已取消退出系统!") << std::endl;
}

void Funcs::Addperson(std::vector<Message>& vec, Message& messages)
{
	Funcs other;
	Prints::AddMessage(vec,messages);
	Prints::Dealy(800);
	other.SaveFile(vec);
	std::cout << Blank(6) << "   操作成功!" << std::endl;
}

void Funcs::Deletely(std::vector<Message>& vec, Message& messages)
{
	std::cout << Blank(4) << "    >------------------------------------------<" << std::endl;
	std::cout << Blank(5) << "请输入删除编号:";
	int id,i = 0;
	Funcs v;
	std::cin >> id;
	std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << "   " << std::left << std::setw(20) << "姓名" << std::setw(20) << "编号" << "工资" << std::endl;
	for (auto ids : vec)
	{
		if (ids.id == id)
		{
			std::cout << Blank(4) << std::left << std::setw(20) << ids.name << std::setw(20) << ids.id
				<< ids.wage << std::endl << std::endl;
			std::cout << Blank(4) << "是否删除匹配数据?\t\t\ty[Y]/n[N]" << std::endl << std::endl << Blank(6) << "     请选择:";
			int num = Prints::Judge();
			if (num == 1)
			{
				vec.erase(vec.begin() + i);
				Funcs::SaveFile(vec);
				Prints::Dealy(800);
				std::cout << std::endl << Blank(6) << "    操作成功!" << std::endl;
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    已取消删除！" : "无效操作已取消删除！") << std::endl;
			return;
		}
		i++;
	}
	std::cout << std::endl << Blank(6) << "    无匹配数据！" << std::endl;
}

void Funcs::Modify(std::vector<Message>& vec, Message& messages)
{
	std::cout << Blank(4) << "    >------------------------------------------<" << std::endl;
	std::cout << Blank(5) << "请输入修改编号:";
	int id, i = 0;
	Funcs v;
	std::cin >> id;
	std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << "   " << std::left << std::setw(20) << "姓名" << std::setw(20) << "编号" << "工资" << std::endl;
	for (auto ids : vec)
	{
		if (ids.id == id)
		{
			std::cout << Blank(4) << std::left << std::setw(20) << ids.name << std::setw(20) << ids.id
				<< ids.wage << std::endl << std::endl;
			std::cout << Blank(4) << "是否修改匹配数据?\t\t\ty[Y]/n[N]" << std::endl << std::endl << Blank(6) << "     请选择:";
			int num = Prints::Judge();
			if (num == 1)
			{
				std::cout << Prints::Blank(4) << ">--------------根据提示录入信息--------------<" << std::endl;
				std::cout << std::endl << Prints::Blank(5) << "姓名:";
				std::cin >> messages.name;
				std::cout << std::endl << Prints::Blank(5) << "编号:";
				std::cin >> messages.id;
				std::cout << std::endl << Prints::Blank(5) << "工资:";
				std::cin >> messages.wage;
				vec.at(i) = messages;
				Funcs::SaveFile(vec);
				Prints::Dealy(800);
				std::cout << std::endl << Blank(6) << "    操作成功!" << std::endl;
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    已取消操作！" : "无效操作已取消操作！") << std::endl;
			return;
		}
		i++;
	}
	std::cout << std::endl << Blank(6) << "    无匹配数据！" << std::endl;
}

void Funcs::View(std::vector<Message>& vec, Message& messages)
{
	std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << "   " << std::left << std::setw(20) << "姓名" << std::setw(20) << "编号" << "工资" << std::endl;
	for (auto message : vec)
	{
		if (vec.size() < 7)
			std::cout << std:: endl;
		std::cout << Blank(4) << "   " << std::left << std::setw(20) << message.name << std::setw(20)
			<< message.id << message.wage << std::endl << std::endl;
	}
}

void Funcs::Search(std::vector<Message>& vec, Message& messages)
{
	typedef int (*Fu)(Message message, std::string x);
	Fu fSearch[] = { (Fu)Searchs::NameSearch,(Fu)Searchs::IdSearch,(Fu)Searchs::WageSearch,(Fu)Searchs::Similarity };
	int num;
	while (1)
	{
		Searchs::MenuSearch();
		num = Prints::Convert();
		if(num > 0 && num < 5)
		{
			std::cout << Blank(4) << "   >--------------------------------------<" << std::endl;
			std::cout << Blank(5) << "请输入查找信息:";
			int i = 0;
			std::string xx1,xx2;
			std::cin >> xx1;
			if (num == 3)
			{
				std::cout << Blank(5) << "请输入查找信息2:";
				std::cin >> xx2;
				xx1 = xx1 + "," + xx2;
			}
			std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
			std::cout << Blank(4) << "   " << std::left << std::setw(20) << "姓名" << std::setw(20) 
				<< "编号" << "工资" << std::endl;
			for (auto message : vec)
			{
				if (fSearch[num - 1](message, xx1))
				{
					std::cout << std::endl << Blank(4) << "   " << std::setw(20) << std::left << message.name 
						<< std::setw(20)<< message.id << message.wage << std::endl;
				}
				i++;
			}
			std::cout << std::endl << Blank(5) << "     ";
			system("pause");
		}
		else if (num == 5)
		{
			std::cout << Blank(5) << "     即将返回主菜单!" << std::endl;
			break;
		}
		else
		{
			std::cout << Blank(6) << "   无效输入!" << std::endl;
			std::cout << std::endl << Blank(5) << "     ";
			system("pause");
		}
	}
}

void Funcs::Sorts(std::vector<Message>& vec, Message& messages)
{
	typedef int (*Ff)(std::vector<Message> vec, int j, int i);
	Ff function[] = { (Ff)Sort::NameSort,(Ff)Sort::IdSort,(Ff)Sort::WageSort};
	while (1)
	{
		Sort::MenuSort();
		int num = Prints::Convert();
		if (num > 0 && num < 4)
		{
			for (int j = 0; j < vec.size(); j++)
			{
				for (int i = j + 1; i < vec.size(); i++)
				{
					if (function[num - 1](vec, j, i))
					{
						messages = vec.at(j);
						vec.at(j) = vec.at(i);
						vec.at(i) = messages;
					}
				}
			}
			Funcs::View(vec, messages);
		}
		else if (num == 4)
		{
			std::cout << Blank(5) << "     即将返回主菜单!" << std::endl;
			break;
		}
		else
		{
			std::cout << std::endl << Blank(6) << "无效操作!" << std::endl;
		}
		std::cout << Blank(5) << "     ";
		system("pause");
	}
}



