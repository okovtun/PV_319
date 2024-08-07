﻿//Files
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	cout << "Hello Files" << endl;

	std::ofstream fout;				//1) Создаем поток
	fout.open("File.txt", std::ios_base::app);			//2) Открываем поток. При открытии потока, 
									//	 мы указываем в какой именно файл мы будем писать.
	//std::ios_base::app (append) - дописывать в конец файла.
	fout << "Hello Files" << endl;	//3) Пишем в поток
	fout << "Привет" << endl;
	fout.close();					//4) Закрываем поток. Потоки обязательно нужно закрывать,
									//	 если не закрывать потоки, это может привести к непредвиденным последствиям.
									//	 (Behaviour is undefined)

	system("notepad File.txt");
#endif // WRITE_TO_FILE

	//1) Создание и открытие потока можно совместить:
	std::ifstream fin("File.txt");
	//2) При чтении обязательно нужно проверять, открылся поток, или нет:
	if (fin.is_open())
	{
		//3) Чтение из файла:
		while (!fin.eof())	//Пока НЕ конец файла - eof(End Of File) читаем поток
		{
			const int SIZE = 1024000;
			char buffer[SIZE]{};
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}

		//4) Поток есть смысл закрывать только в том случае, если он был открыт.
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
}