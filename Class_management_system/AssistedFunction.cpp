#include<iostream>
#include<chrono>
#include<thread>
#include "Message.h"


void Prints::Menu()
{
	std::cout << Blank(5) << ">------------------------------<" << std::endl;
	std::cout << Blank(6) << "Classģʽ-System" << std::endl;
	std::cout << Blank(6) << "  1�������Ϣ" << std::endl;
	std::cout << Blank(6) << "  2��ɾ����Ϣ" << std::endl;
	std::cout << Blank(6) << "  3���޸���Ϣ" << std::endl;
	std::cout << Blank(6) << "  4�������Ϣ" << std::endl;
	std::cout << Blank(6) << "  5��������Ϣ" << std::endl;
	std::cout << Blank(6) << "  6����Ϣ����" << std::endl;
	std::cout << Blank(6) << "  0���˳�ϵͳ" << std::endl;
	std::cout << Blank(5) << ">------------------------------<" << std::endl;
	std::cout << Blank(6) << "    ��ѡ��:";
}

std::string Prints::Blank(int num)
{
	std::string tabs(num, '\t');
	return tabs;
}

int Prints::Judge()
{
	char c;
	std::cin >> c;
	if (c == 'y' || c == 'Y')
		return 1;
	else if (c == 'n' || c == 'N')
		return 0;
	else
		return -1;
}

int Prints::Convert()
{
	char c[20];
	std::cin >> c;
	return atoi(c);
}

void Prints::AddMessage(std::vector<Message>& vec, Message& messages)
{
	std::cout << Prints::Blank(4) << ">--------------������ʾ¼����Ϣ--------------<" << std::endl;
	std::cout << std::endl << Prints::Blank(5) << "����:";
	std::cin >> messages.name;
	std::cout << std::endl << Prints::Blank(5) << "���:";
	std::cin >> messages.id;
	std::cout << std::endl << Prints::Blank(5) << "����:";
	std::cin >> messages.wage;
	vec.push_back(messages);
}

void Prints::Dealy(int num)
{
	std::cout << Blank(6) << "    ";
	while (num -= 200)
	{
		auto time_t = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(num);
		std::cout << ".";
		std::this_thread::sleep_until(time_t);
	}
	auto time_t = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(num);
	std::this_thread::sleep_until(time_t);
	std::cout << std::endl;
}

