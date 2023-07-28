#pragma once
#include<string>
#include<vector>


class Message
{
public:
	std::string name;
	int id;
	std::string wage;
};


class Prints
{
public:
	std::vector<Message>vec;
	static void Menu();
	static std::string Blank(int num);
	static int Judge();
	static int Convert();
	static void AddMessage(std::vector<Message>& vec, Message& messages);
	static void Dealy(int num);
};

class Funcs :private Prints
{
public:
	static void SaveFile(std::vector<Message>vec);
	std::vector<Message> Load(std::vector<Message>&vec, Message& messages);
	static void Exits(std::vector<Message>& vec,Message& messages);
	static void Addperson(std::vector<Message>& vec, Message& messages);
	static void Deletely(std::vector<Message>& vec, Message& messages);
	static void Modify(std::vector<Message>& vec, Message& messages);
	static void View(std::vector<Message>& vec, Message& messages);
	static void Search(std::vector<Message>& vec, Message& messages);
	static void Sorts(std::vector<Message>& vec, Message& messages);
};

