#pragma once
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<string>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class Pharmacy
{
private:
	//порядковый номер лекарства 
	vector<int> id;
	//наименование лекарства
	vector<string> name;
	//Лекарственная форма лекарства
	vector<string> type;
	//Производитель лекарства
	vector<string> maker;
	//Стоимость лекарства
	vector<double> price;
	//Колличество штук
	vector<int> amount;

	int nextid = 0;
	//Имя файла, в который сохраняются данные
	string filename = "data.txt";
	//Кол-во столбцов таблицы
	static const int numcol = 6;
	//Массив имен-заголовков столбцов таблицы
	const string columns[numcol] = { "ID", "Название", "Тип", "Производитель", "Цена", "Кол-во" };
	//Переменная влияющая на размер таблицы (кол-во отступов для выравнивания по середине содержимого ячейки)
	static const int vertical = 9;
	//Разделяющая линия строк таблицы
	string horizontal = string(vertical * 2 * numcol - (vertical % 2 == 0 ? vertical / 2 - 1 : vertical / 2), '-');

	//Формирование заголовка и структуры таблицы
	void CreateTable();
	
	void SaveTxt();
	
	//Вывод на экран и сохранение в текстовый файл
	void Print();
	
	//Поиск по столбцу и ключу и вывод
	int PrintFind(string column, string key);
	
	int PrintFind(string column, double key);
	
	int PrintFind(string column, int key);
	
	//Фильтрация по столбцу и ключу и вывод
	int PrintFilt(string column, string key);
	
	int PrintFilt(string column, double key);
	
	int PrintFilt(string column, int key);
	
	//Сортировка по стобцу и ключу и вывод
	void PrintSort(string column, bool asc = true);
	
	void SortTable(vector<string> v, bool asc = true);
	
	void SortTable(vector<double> v, bool asc = true);
	
	void SortTable(vector<int> v, bool asc = true);
	
	//Добавление новой записи в конец
	void Create(string name, string type, string maker, double price, int amount);
	
	void Create(int id, string name, string type, string maker, double price, int amount);
	
	//Удаление записи по id
	void Delete(int id);
	
	//Обновление записи по id
	void Update(int id, string name = "", string type = "", string maker = "", double price = 0.0, int amount = 0);
	
	//Открываем файл data на перезапись
	ofstream WriteOpen();
	
	//Открываем файл data на дозапись
	ofstream UpdateOpen();
	
	//Открываем файл для записи в таблицу
	ifstream ReadOpen();
	
	//Читаем данные с файла для записи в таблицу
	void ReadFile();
	
public:
	Pharmacy();
	
	Pharmacy(string filename);
	
	Pharmacy(string name, string type, string maker, double price, int amount);
	
	Pharmacy(int id, string name, string type, string maker, double price, int amount);
	
	void menu();
	
};

