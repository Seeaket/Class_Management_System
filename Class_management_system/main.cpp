#include<iostream>
#include<vector>
#include<string>
#include"Message.h"
using namespace std;


int main()
{
	Prints printer;
	Message messages;
	Funcs other;
	printer.vec.clear();
	printer.vec = other.Load(printer.vec,messages);
	while(1)
	{
		system("cls");
		printer.Menu();
		typedef int (*Func)(vector<Message>&vec,Message& messages);
		Func function[] = {(Func)Funcs::Exits,(Func)Funcs::Addperson,(Func)Funcs::Deletely,(Func)Funcs::Modify,
			(Func)Funcs::View,(Func)Funcs::Search,(Func)Funcs::Sorts};
		int num = printer.Convert();
		if (num >= 0 && num <= 6)
			function[num](printer.vec,messages);
		else
		{
			cout << printer.Blank(6) << "ÎÞÐ§ÊäÈë!" << endl;
		}
		cout << printer.Blank(5) <<"     ";
		system("pause");
	}
	return 0;
}