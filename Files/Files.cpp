#include <iostream>
#include <fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	cout << "Hello World!";
	ofstream fout;				//1) Создаем поток (Output File Stream)
	fout.open("File.txt", std::ios_base::app);		//2) Открываем поток
								// Флаг 'std::ios_base::app' (append) - дописывает вывод в конце файла
	fout << "Hello World!"<<endl;		//3) Выполняем запись в файл
	fout.close();				//4) Когда поток уже не нужен, его ОБЯЗАТЕЛЬНО нужно закрыть!!!
	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	char filename[_MAX_FNAME]{};
	cout << "Введите имя файла: ";
	cin.getline(filename, _MAX_FNAME);
	
	ifstream fin;				//1) Создаем поток (Output File Stream)
	fin.open(filename);
	if (fin.is_open())
	{
		//TODO: read file
		//1) Создаем буфер, в который будем выполнять чтение:
		const int SIZE = 256;
		char buffer[SIZE] = {};
		//2) Запускаем цикл, который будет читать файл до конца:
		while (!fin.eof())
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();	//закрываем поток только в том случае, если он открыт
	}
	else
	{
		cout << "Error: File not found" << endl;
	}
	system("notepad File.txt");
#endif // READ_FROM_FILE	
}