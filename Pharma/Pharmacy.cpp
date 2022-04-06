#include "Pharmacy.h"

void Pharmacy::CreateTable()
{
	system("cls");
	cout << string((vertical % 2 == 0 ? vertical / 2 : vertical / 2 + 1), '\t') << "Программа \"Аптечный склад\"" << endl;
	cout << horizontal << endl;
	cout << "|" << setw(vertical / 2 + 1) << columns[0] << setw(vertical / 2 - 1) << "|";
	for (size_t i = 1; i < numcol; i++)
		cout << "|" << setw(vertical + columns[i].length() / 2) << columns[i] << setw(vertical - columns[i].length() / 2) << "|";
	cout << endl << horizontal << endl;
}

void Pharmacy::SaveTxt()
{
	ofstream out = WriteOpen();

	int numrow = this->name.size();

	for (int i = 0; i < numrow; i++)
	{
		out << id[i] << ' ';
		out << name[i] << ' ';
		out << type[i] << ' ';
		out << maker[i] << ' ';
		out << fixed << setprecision(2) << price[i] << ' ';
		out << amount[i] << ' ';
		out << endl;
	}
	out.close();
}

void Pharmacy::Print()
{
	CreateTable();
	int numrow = this->name.size();

	for (int i = 0; i < numrow; i++)
	{
		cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
		cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
		cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
		cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
		cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
		cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
		cout << endl << horizontal << endl;
	}
}

int Pharmacy::PrintFind(string column, string key)
{
	CreateTable();
	int numrow = this->name.size();
	int countfind = 0;
	for (int i = 0; i < numrow; i++)
	{
		cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
		cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
		cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
		cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
		cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
		cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
		bool flag = false;
		if (column == "Название" && name[i].find(key) != -1)
			flag = true;
		if (column == "Тип" && type[i].find(key) != -1)
			flag = true;
		if (column == "Производитель" && maker[i].find(key) != -1)
			flag = true;
		if (flag)
		{
			cout << " Найдено!";
			countfind++;
		}
		cout << endl << horizontal << endl;
	}
	return countfind;
}

int Pharmacy::PrintFind(string column, double key)
{
	CreateTable();
	int numrow = this->name.size();
	int countfind = 0;
	for (int i = 0; i < numrow; i++)
	{
		cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
		cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
		cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
		cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
		cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
		cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
		if (column == "Цена" && price[i] == key)
		{
			cout << " Найдено!";
			countfind++;
		}

		cout << endl << horizontal << endl;
	}
	return countfind;
}

int Pharmacy::PrintFind(string column, int key)
{
	CreateTable();
	int numrow = this->name.size();
	int countfind = 0;
	for (int i = 0; i < numrow; i++)
	{
		cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
		cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
		cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
		cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
		cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
		cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
		if (column == "Кол-во" && amount[i] == key)
		{
			cout << " Найдено!";
			countfind++;
		}
		cout << endl << horizontal << endl;
	}
	return countfind;
}

int Pharmacy::PrintFilt(string column, string key)
{
	CreateTable();
	int numrow = this->name.size();
	int countfilt = 0;
	for (int i = 0; i < numrow; i++)
	{
		bool flag = false;
		if (column == "Название" && name[i].find(key) != -1)
			flag = true;
		if (column == "Тип" && type[i].find(key) != -1)
			flag = true;
		if (column == "Производитель" && maker[i].find(key) != -1)
			flag = true;

		if (flag)
		{
			countfilt++;
			cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
			cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
			cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
			cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
			cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
			cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
			cout << endl << horizontal << endl;
		}
	}
	return countfilt;
}

int Pharmacy::PrintFilt(string column, double key)
{
	CreateTable();
	int numrow = this->name.size();
	int countfilt = 0;
	for (int i = 0; i < numrow; i++)
	{
		if (column == "Цена" && price[i] == key)
		{
			countfilt++;
			cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
			cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
			cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
			cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
			cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
			cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
			cout << endl << horizontal << endl;
		}
	}
	return countfilt;
}

int Pharmacy::PrintFilt(string column, int key)
{
	CreateTable();
	int numrow = this->name.size();
	int countfilt = 0;
	for (int i = 0; i < numrow; i++)
	{
		if (column == "Кол-во" && amount[i] == key)
		{
			countfilt++;
			cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
			cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
			cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
			cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
			cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
			cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
			cout << endl << horizontal << endl;
		}
	}
	return countfilt;
}

void Pharmacy::PrintSort(string column, bool asc)
{
	CreateTable();
	int numrow = this->name.size();

	if (column == "ID" && asc)
		SortTable(id);
	else if (column == "ID")
		SortTable(id, 0);

	if (column == "Название" && asc)
		SortTable(name);
	else if (column == "Название")
		SortTable(name, 0);

	if (column == "Тип" && asc)
		SortTable(type);
	else if (column == "Тип")
		SortTable(type, 0);

	if (column == "Производитель" && asc)
		SortTable(maker);
	else if (column == "Производитель")
		SortTable(maker, 0);

	if (column == "Цена" && asc)
		SortTable(price);
	else if (column == "Цена")
		SortTable(price, 0);

	if (column == "Кол-во" && asc)
		SortTable(amount);
	else if (column == "Кол-во")
		SortTable(amount, 0);

	for (int i = 0; i < numrow; i++)
	{
		cout << "|" << setw(vertical / 2) << id[i] << setw(vertical / 2) << "|";
		cout << "|" << setw(vertical + name[i].length() / 2) << name[i] << setw(vertical - name[i].length() / 2) << "|";
		cout << "|" << setw(vertical + type[i].length() / 2) << type[i] << setw(vertical - type[i].length() / 2) << "|";
		cout << "|" << setw(vertical + maker[i].length() / 2) << maker[i] << setw(vertical - maker[i].length() / 2) << "|";
		cout << "|" << setw(vertical + (to_string(price[i]).length() - 4) / 2) << fixed << setprecision(2) << price[i] << setw(vertical - (to_string(price[i]).length() - 4) / 2) << "|";
		cout << "|" << setw(vertical + to_string(amount[i]).length() / 2) << amount[i] << setw(vertical - to_string(amount[i]).length() / 2) << "|";
		cout << endl << horizontal << endl;
	}
}

void Pharmacy::SortTable(vector<string>& v, bool asc)
{
	int n = v.size();
	string tname = "", ttype = "", tmaker = "";
	double tprice = 0.0;
	int tid = 0, tamount = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (asc ? v[i] > v[j]: v[i] < v[j])
			{
				tid = id[i];
				id[i] = id[j];
				id[j] = tid;

				tname = name[i];
				name[i] = name[j];
				name[j] = tname;

				ttype = type[i];
				type[i] = type[j];
				type[j] = ttype;

				tmaker = maker[i];
				maker[i] = maker[j];
				maker[j] = tmaker;

				tprice = price[i];
				price[i] = price[j];
				price[j] = tprice;

				tamount = amount[i];
				amount[i] = amount[j];
				amount[j] = tamount;
			}
		}
}

void Pharmacy::SortTable(vector<double>& v, bool asc)
{
	int n = v.size();
	string tname = "", ttype = "", tmaker = "";
	double tprice = 0.0;
	int tid = 0, tamount = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (asc ? v[i] > v[j]: v[i] < v[j])
			{
				tid = id[i];
				id[i] = id[j];
				id[j] = tid;

				tname = name[i];
				name[i] = name[j];
				name[j] = tname;

				ttype = type[i];
				type[i] = type[j];
				type[j] = ttype;

				tmaker = maker[i];
				maker[i] = maker[j];
				maker[j] = tmaker;

				tprice = price[i];
				price[i] = price[j];
				price[j] = tprice;

				tamount = amount[i];
				amount[i] = amount[j];
				amount[j] = tamount;
			}
		}
}

void Pharmacy::SortTable(vector<int>& v, bool asc)
{
	int n = v.size();
	string tname = "", ttype = "", tmaker = "";
	double tprice = 0.0;
	int tid = 0, tamount = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (asc ? v[i] > v[j]: v[i] < v[j])
			{
				tid = id[i];
				id[i] = id[j];
				id[j] = tid;

				tname = name[i];
				name[i] = name[j];
				name[j] = tname;

				ttype = type[i];
				type[i] = type[j];
				type[j] = ttype;

				tmaker = maker[i];
				maker[i] = maker[j];
				maker[j] = tmaker;

				tprice = price[i];
				price[i] = price[j];
				price[j] = tprice;

				tamount = amount[i];
				amount[i] = amount[j];
				amount[j] = tamount;
			}
		}
}

void Pharmacy::Create(string name, string type, string maker, double price, int amount)
{
	this->id.push_back(nextid++);
	this->name.push_back(name);
	this->type.push_back(type);
	this->maker.push_back(maker);
	this->price.push_back(price);
	this->amount.push_back(amount);
	SaveTxt();
}

void Pharmacy::Create(int id, string name, string type, string maker, double price, int amount)
{
	this->id.push_back(id);
	this->name.push_back(name);
	this->type.push_back(type);
	this->maker.push_back(maker);
	this->price.push_back(price);
	this->amount.push_back(amount);
	SaveTxt();
}

void Pharmacy::Delete(int id)
{
	for (size_t i = 0; i < nextid; i++)
	{
		if (this->id[i] == id)
		{
			this->id.erase(this->id.begin() + i);
			this->name.erase(name.begin() + i);
			this->type.erase(type.begin() + i);
			this->maker.erase(maker.begin() + i);
			this->price.erase(price.begin() + i);
			this->amount.erase(amount.begin() + i);
			break;
		}
	}
	SaveTxt();
}

void Pharmacy::Update(int id, string name, string type, string maker, double price, int amount)
{
	for (size_t i = 0; i < nextid; i++)
	{
		if (this->id[i] == id)
		{
			if (name != "")
				this->name[i] = name;
			if (type != "")
				this->type[i] = type;
			if (maker != "")
				this->maker[i] = maker;
			if (price != 0.0)
				this->price[i] = price;
			if (amount != 0)
				this->amount[i] = amount;
			break;
		}
	}

	SaveTxt();
}

ofstream Pharmacy::WriteOpen()
{
	ofstream out(this->filename);
	if (!out.is_open())
	{
		cout << endl << "Файл " << filename << " не открылся!" << endl;
		_getch();
	}
	return out;
}

ofstream Pharmacy::UpdateOpen()
{
	ofstream out(this->filename, std::ios::app);
	if (!out.is_open())
	{
		cout << endl << "Файл " << filename << " не открылся!" << endl;
		_getch();
	}
	return out;
}

ifstream Pharmacy::ReadOpen()
{
	ifstream  in(filename);
	if (!(in.is_open()))
	{
		cout << endl << "Файл " << filename << " не открылся!" << endl;
		_getch();
	}
	return in;
}

void Pharmacy::ReadFile()
{
	ifstream  in = ReadOpen();
	if (in.peek() != EOF)
	{
		string tname = "", ttype = "", tmaker = "";
		double tprice = 0.0;
		int tid = 0, tamount = 0;

		while (true)
		{
			in >> tid;
			in >> tname;
			in >> ttype;
			in >> tmaker;
			in >> tprice;
			in >> tamount;
			if (in.eof())
				break;
			Create(tid, tname, ttype, tmaker, tprice, tamount);
		}
		nextid = tid + 1;
	}
	in.close();
}

Pharmacy::Pharmacy()
{
	this->id.push_back(this->name.size());
	this->name.push_back("");
	this->type.push_back("");
	this->maker.push_back("");
	this->price.push_back(0.0);
	this->amount.push_back(0);
}

Pharmacy::Pharmacy(string filename)
{
	this->filename = filename;
	ReadFile();
}

Pharmacy::Pharmacy(string name, string type, string maker, double price, int amount)
{
	this->id.push_back(this->name.size());
	this->name.push_back(name);
	this->type.push_back(type);
	this->maker.push_back(maker);
	this->price.push_back(price);
	this->amount.push_back(amount);
}

Pharmacy::Pharmacy(int id, string name, string type, string maker, double price, int amount)
{
	this->id.push_back(id);
	this->name.push_back(name);
	this->type.push_back(type);
	this->maker.push_back(maker);
	this->price.push_back(price);
	this->amount.push_back(amount);
}

void Pharmacy::menu()
{
	bool showGeneralPrint = true;
	while (true)
	{
		int choice;
		if (showGeneralPrint)
			this->Print();
		showGeneralPrint = true;
		cout << "Выберите необходимую команду:" << endl;
		cout << "1) Добавление новой записи;" << endl;
		cout << "2) Удаление записи;" << endl;
		cout << "3) Обновление записи;" << endl;
		cout << "4) Поиск записей;" << endl;
		cout << "5) Фильтрация записей;" << endl;
		cout << "6) Сортировка записей;" << endl;
		cout << "0) Выход из программы." << endl;
		cout << ">>> "; cin >> choice;

		string tname = "", ttype = "", tmaker = "";
		double tprice = 0.0;
		int tamount = 0, id = 1, count = 0;
		bool asc = false;

		switch (choice)
		{
		case 1:
			cout << endl << "Введите поля:" << endl;
			cout << "Название:\t\t";
			cin >> tname;
			cout << "Тип лекарства:\t\t";
			cin >> ttype;
			cout << "Производитель:\t\t";
			cin >> tmaker;
			cout << "Цена за упаковку:\t";
			cin >> tprice;
			cout << "Кол-во упаковок:\t";
			cin >> tamount;
			this->Create(tname, ttype, tmaker, tprice, tamount);
			cout << "Запись успешно добавлена!";
			_getch();
			break;
		case 2:
			if (!this->name.empty())
			{
				cout << "Введите ID записи:   "; cin >> id;
				if (id >= 0 && nextid > id)
				{
					this->Delete(id);
					cout << "Запись успешно удалена!";
				}
				else
					cout << "Ошибка ввода ID!";
			}
			else
			{
				cout << "Ошибка! Таблица пуста!";
			}
			_getch();
			break;
		case 3:
			while (true)
			{
				if (!this->name.empty())
				{
					cout << "Введите ID записи:   "; cin >> id;
					if (id > 0 && nextid > id)
					{
						cout << endl << "Выберите столбец, который хотите изменить:" << endl;
						cout << "1. Название;" << endl;
						cout << "2. Тип;" << endl;
						cout << "3. Производитель;" << endl;
						cout << "4. Цена;" << endl;
						cout << "5. Кол-во;" << endl;
						cout << "0. Вернуться в главное меню." << endl;
						cout << ">>> "; cin >> choice;
						if (choice >= 1 && choice < numcol)
						{
							if (choice == 1)
							{
								cout << "Введите название:   "; cin >> tname;
								Update(id, tname);
							}
							if (choice == 2)
							{
								cout << "Введите тип лекарства:   "; cin >> ttype;
								Update(id, "", ttype);
							}
							if (choice == 3)
							{
								cout << "Введите производителя:   "; cin >> tmaker;
								Update(id, "", "", tmaker);
							}
							if (choice == 4)
							{
								cout << "Введите цену упаковки:   "; cin >> tprice;
								Update(id, "", "", "", tprice);
							}
							if (choice == 5)
							{
								cout << "Введите кол-во упаковок:   "; cin >> tamount;
								Update(id, "", "", "", 0.0, tamount);
							}
						}
						else if (choice == 0)
						{
							break;
						}
						else
						{
							cout << "Ошибка ввода! Введите ещё раз.";
							_getch();
							continue;
						}
						cout << "Запись успешно обновлена!";
						_getch();
					}
					else
					{
						cout << "Ошибка ввода ID!";
						_getch();
						continue;
					}
				}
				else
				{
					cout << "Ошибка! Таблица пуста!";
					_getch();
				}
				break;
			}
			break;
		case 4:
			while (true)
			{
				if (!this->name.empty())
				{
					cout << endl << "Выберите искомый столбец:" << endl;
					cout << "1. Название;" << endl;
					cout << "2. Тип;" << endl;
					cout << "3. Производитель;" << endl;
					cout << "4. Цена;" << endl;
					cout << "5. Кол-во;" << endl;
					cout << "0. Отмена поиска." << endl;
					cout << ">>> "; cin >> choice;
					if (choice >= 1 && choice < numcol)
					{
						if (choice == 1)
						{
							cout << "Введите название:   "; cin >> tname;
							count = PrintFind(columns[choice], tname);
						}
						if (choice == 2)
						{
							cout << "Введите тип лекарства:   "; cin >> ttype;
							count = PrintFind(columns[choice], ttype);
						}
						if (choice == 3)
						{
							cout << "Введите производителя:   "; cin >> tmaker;
							count = PrintFind(columns[choice], tmaker);
						}
						if (choice == 4)
						{
							cout << "Введите цену упаковки:   "; cin >> tprice;
							count = PrintFind(columns[choice], tprice);
						}
						if (choice == 5)
						{
							cout << "Введите кол-во упаковок:   "; cin >> tamount;
							count = PrintFind(columns[choice], tamount);
						}
						showGeneralPrint = false;
					}
					else if (choice == 0)
					{
						break;
					}
					else
					{
						cout << "Ошибка ввода! Введите ещё раз.";
						_getch();
						continue;
					}
					cout << "Найдено " << count << " записей." << endl;
				}
				else
				{
					cout << "Ошибка! Таблица пуста!";
					_getch();
				}
				break;
			}
			break;
		case 5:
			while (true)
			{
				if (!this->name.empty())
				{
					cout << endl << "Выберите искомый столбец:" << endl;
					cout << "1. Название;" << endl;
					cout << "2. Тип;" << endl;
					cout << "3. Производитель;" << endl;
					cout << "4. Цена;" << endl;
					cout << "5. Кол-во;" << endl;
					cout << "0. Отмена фильтрации." << endl;
					cout << ">>> "; cin >> choice;
					if (choice >= 1 && choice < numcol)
					{
						if (choice == 1)
						{
							cout << "Введите название:   "; cin >> tname;
							count = PrintFilt(columns[choice], tname);
						}
						if (choice == 2)
						{
							cout << "Введите тип лекарства:   "; cin >> ttype;
							count = PrintFilt(columns[choice], ttype);
						}
						if (choice == 3)
						{
							cout << "Введите производителя:   "; cin >> tmaker;
							count = PrintFilt(columns[choice], tmaker);
						}
						if (choice == 4)
						{
							cout << "Введите цену упаковки:   "; cin >> tprice;
							count = PrintFilt(columns[choice], tprice);
						}
						if (choice == 5)
						{
							cout << "Введите кол-во упаковок:   "; cin >> tamount;
							count = PrintFilt(columns[choice], tamount);
						}
						showGeneralPrint = false;
					}
					else if (choice == 0)
					{
						break;
					}
					else
					{
						cout << "Ошибка ввода! Введите ещё раз.";
						_getch();
						continue;
					}
					cout << "Найдено " << count << " записей." << endl;
				}
				else
				{
					cout << "Ошибка! Таблица пуста!";
					_getch();
				}
				break;
			}
			break;
		case 6:
			while (true)
			{
				if (!this->name.empty())
				{
					cout << endl << "Выберите искомый столбец:" << endl;
					cout << "1. Название;" << endl;
					cout << "2. Тип;" << endl;
					cout << "3. Производитель;" << endl;
					cout << "4. Цена;" << endl;
					cout << "5. Кол-во;" << endl;
					cout << "0. Отмена сортировки." << endl;
					cout << ">>> "; cin >> choice;
					if (choice >= 1 && choice < numcol)
					{
						cout << "Осуществить сортировку по возрастанию? (0-Нет, 1-Да): ";
						cin >> asc;
						PrintSort(columns[choice], asc);
						showGeneralPrint = false;
					}
					else if (choice == 0)
					{
						PrintSort(columns[0], true);
						break;
					}
					else
					{
						cout << "Ошибка ввода! Введите ещё раз.";
						_getch();
						continue;
					}
					cout << "Сортировка " << (asc ? "по возрастанию" : "по убыванию") << " выполнена." << endl;
				}
				else
				{
					cout << "Ошибка! Таблица пуста!";
					_getch();
				}
				break;
			}
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Ошибка ввода команды!";
			_getch();
			break;
		}
	}
}
