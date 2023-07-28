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
	std::cout << Blank(4) << "     �Ƿ�ȷ���˳�ϵͳ?        y[Y]/n[N]" << std::endl << Blank(6) << "    ��ѡ��:";
	int num = Judge();
	if (num == 1)
	{
		vec.clear();
		vec.shrink_to_fit();
		exit(0);
	}
	std::cout << std::endl <<  Blank(6) << (num == 0 ? "   ��ȡ���˳�!" : "��Ч������ȡ���˳�ϵͳ!") << std::endl;
}

void Funcs::Addperson(std::vector<Message>& vec, Message& messages)
{
	Funcs other;
	Prints::AddMessage(vec,messages);
	Prints::Dealy(800);
	other.SaveFile(vec);
	std::cout << Blank(6) << "   �����ɹ�!" << std::endl;
}

void Funcs::Deletely(std::vector<Message>& vec, Message& messages)
{
	std::cout << Blank(4) << "    >------------------------------------------<" << std::endl;
	std::cout << Blank(5) << "������ɾ�����:";
	int id,i = 0;
	Funcs v;
	std::cin >> id;
	std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << "   " << std::left << std::setw(20) << "����" << std::setw(20) << "���" << "����" << std::endl;
	for (auto ids : vec)
	{
		if (ids.id == id)
		{
			std::cout << Blank(4) << std::left << std::setw(20) << ids.name << std::setw(20) << ids.id
				<< ids.wage << std::endl << std::endl;
			std::cout << Blank(4) << "�Ƿ�ɾ��ƥ������?\t\t\ty[Y]/n[N]" << std::endl << std::endl << Blank(6) << "     ��ѡ��:";
			int num = Prints::Judge();
			if (num == 1)
			{
				vec.erase(vec.begin() + i);
				Funcs::SaveFile(vec);
				Prints::Dealy(800);
				std::cout << std::endl << Blank(6) << "    �����ɹ�!" << std::endl;
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    ��ȡ��ɾ����" : "��Ч������ȡ��ɾ����") << std::endl;
			return;
		}
		i++;
	}
	std::cout << std::endl << Blank(6) << "    ��ƥ�����ݣ�" << std::endl;
}

void Funcs::Modify(std::vector<Message>& vec, Message& messages)
{
	std::cout << Blank(4) << "    >------------------------------------------<" << std::endl;
	std::cout << Blank(5) << "�������޸ı��:";
	int id, i = 0;
	Funcs v;
	std::cin >> id;
	std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << "   " << std::left << std::setw(20) << "����" << std::setw(20) << "���" << "����" << std::endl;
	for (auto ids : vec)
	{
		if (ids.id == id)
		{
			std::cout << Blank(4) << std::left << std::setw(20) << ids.name << std::setw(20) << ids.id
				<< ids.wage << std::endl << std::endl;
			std::cout << Blank(4) << "�Ƿ��޸�ƥ������?\t\t\ty[Y]/n[N]" << std::endl << std::endl << Blank(6) << "     ��ѡ��:";
			int num = Prints::Judge();
			if (num == 1)
			{
				std::cout << Prints::Blank(4) << ">--------------������ʾ¼����Ϣ--------------<" << std::endl;
				std::cout << std::endl << Prints::Blank(5) << "����:";
				std::cin >> messages.name;
				std::cout << std::endl << Prints::Blank(5) << "���:";
				std::cin >> messages.id;
				std::cout << std::endl << Prints::Blank(5) << "����:";
				std::cin >> messages.wage;
				vec.at(i) = messages;
				Funcs::SaveFile(vec);
				Prints::Dealy(800);
				std::cout << std::endl << Blank(6) << "    �����ɹ�!" << std::endl;
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    ��ȡ��������" : "��Ч������ȡ��������") << std::endl;
			return;
		}
		i++;
	}
	std::cout << std::endl << Blank(6) << "    ��ƥ�����ݣ�" << std::endl;
}

void Funcs::View(std::vector<Message>& vec, Message& messages)
{
	std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << "   " << std::left << std::setw(20) << "����" << std::setw(20) << "���" << "����" << std::endl;
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
			std::cout << Blank(5) << "�����������Ϣ:";
			int i = 0;
			std::string xx1,xx2;
			std::cin >> xx1;
			if (num == 3)
			{
				std::cout << Blank(5) << "�����������Ϣ2:";
				std::cin >> xx2;
				xx1 = xx1 + "," + xx2;
			}
			std::cout << Blank(4) << ">----------------------------------------------<" << std::endl;
			std::cout << Blank(4) << "   " << std::left << std::setw(20) << "����" << std::setw(20) 
				<< "���" << "����" << std::endl;
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
			std::cout << Blank(5) << "     �����������˵�!" << std::endl;
			break;
		}
		else
		{
			std::cout << Blank(6) << "   ��Ч����!" << std::endl;
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
			std::cout << Blank(5) << "     �����������˵�!" << std::endl;
			break;
		}
		else
		{
			std::cout << std::endl << Blank(6) << "��Ч����!" << std::endl;
		}
		std::cout << Blank(5) << "     ";
		system("pause");
	}
}



