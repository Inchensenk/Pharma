#include "Pharmacy.h"

void Pharmacy::CreateTable()
{
	system("cls");
	cout << string((vertical % 2 == 0 ? vertical / 2 : vertical / 2 + 1), '\t') << "��������� \"�������� �����\"" << endl;
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
		if (column == "��������" && name[i].find(key) != -1)
			flag = true;
		if (column == "���" && type[i].find(key) != -1)
			flag = true;
		if (column == "�������������" && maker[i].find(key) != -1)
			flag = true;
		if (flag)
		{
			cout << " �������!";
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
		if (column == "����" && price[i] == key)
		{
			cout << " �������!";
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
		if (column == "���-��" && amount[i] == key)
		{
			cout << " �������!";
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
		if (column == "��������" && name[i].find(key) != -1)
			flag = true;
		if (column == "���" && type[i].find(key) != -1)
			flag = true;
		if (column == "�������������" && maker[i].find(key) != -1)
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
		if (column == "����" && price[i] == key)
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
		if (column == "���-��" && amount[i] == key)
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

	if (column == "��������" && asc)
		SortTable(name);
	else if (column == "��������")
		SortTable(name, 0);

	if (column == "���" && asc)
		SortTable(type);
	else if (column == "���")
		SortTable(type, 0);

	if (column == "�������������" && asc)
		SortTable(maker);
	else if (column == "�������������")
		SortTable(maker, 0);

	if (column == "����" && asc)
		SortTable(price);
	else if (column == "����")
		SortTable(price, 0);

	if (column == "���-��" && asc)
		SortTable(amount);
	else if (column == "���-��")
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
		cout << endl << "���� " << filename << " �� ��������!" << endl;
		_getch();
	}
	return out;
}

ofstream Pharmacy::UpdateOpen()
{
	ofstream out(this->filename, std::ios::app);
	if (!out.is_open())
	{
		cout << endl << "���� " << filename << " �� ��������!" << endl;
		_getch();
	}
	return out;
}

ifstream Pharmacy::ReadOpen()
{
	ifstream  in(filename);
	if (!(in.is_open()))
	{
		cout << endl << "���� " << filename << " �� ��������!" << endl;
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
		cout << "�������� ����������� �������:" << endl;
		cout << "1) ���������� ����� ������;" << endl;
		cout << "2) �������� ������;" << endl;
		cout << "3) ���������� ������;" << endl;
		cout << "4) ����� �������;" << endl;
		cout << "5) ���������� �������;" << endl;
		cout << "6) ���������� �������;" << endl;
		cout << "0) ����� �� ���������." << endl;
		cout << ">>> "; cin >> choice;

		string tname = "", ttype = "", tmaker = "";
		double tprice = 0.0;
		int tamount = 0, id = 1, count = 0;
		bool asc = false;

		switch (choice)
		{
		case 1:
			cout << endl << "������� ����:" << endl;
			cout << "��������:\t\t";
			cin >> tname;
			cout << "��� ���������:\t\t";
			cin >> ttype;
			cout << "�������������:\t\t";
			cin >> tmaker;
			cout << "���� �� ��������:\t";
			cin >> tprice;
			cout << "���-�� ��������:\t";
			cin >> tamount;
			this->Create(tname, ttype, tmaker, tprice, tamount);
			cout << "������ ������� ���������!";
			_getch();
			break;
		case 2:
			if (!this->name.empty())
			{
				cout << "������� ID ������:   "; cin >> id;
				if (id >= 0 && nextid > id)
				{
					this->Delete(id);
					cout << "������ ������� �������!";
				}
				else
					cout << "������ ����� ID!";
			}
			else
			{
				cout << "������! ������� �����!";
			}
			_getch();
			break;
		case 3:
			while (true)
			{
				if (!this->name.empty())
				{
					cout << "������� ID ������:   "; cin >> id;
					if (id > 0 && nextid > id)
					{
						cout << endl << "�������� �������, ������� ������ ��������:" << endl;
						cout << "1. ��������;" << endl;
						cout << "2. ���;" << endl;
						cout << "3. �������������;" << endl;
						cout << "4. ����;" << endl;
						cout << "5. ���-��;" << endl;
						cout << "0. ��������� � ������� ����." << endl;
						cout << ">>> "; cin >> choice;
						if (choice >= 1 && choice < numcol)
						{
							if (choice == 1)
							{
								cout << "������� ��������:   "; cin >> tname;
								Update(id, tname);
							}
							if (choice == 2)
							{
								cout << "������� ��� ���������:   "; cin >> ttype;
								Update(id, "", ttype);
							}
							if (choice == 3)
							{
								cout << "������� �������������:   "; cin >> tmaker;
								Update(id, "", "", tmaker);
							}
							if (choice == 4)
							{
								cout << "������� ���� ��������:   "; cin >> tprice;
								Update(id, "", "", "", tprice);
							}
							if (choice == 5)
							{
								cout << "������� ���-�� ��������:   "; cin >> tamount;
								Update(id, "", "", "", 0.0, tamount);
							}
						}
						else if (choice == 0)
						{
							break;
						}
						else
						{
							cout << "������ �����! ������� ��� ���.";
							_getch();
							continue;
						}
						cout << "������ ������� ���������!";
						_getch();
					}
					else
					{
						cout << "������ ����� ID!";
						_getch();
						continue;
					}
				}
				else
				{
					cout << "������! ������� �����!";
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
					cout << endl << "�������� ������� �������:" << endl;
					cout << "1. ��������;" << endl;
					cout << "2. ���;" << endl;
					cout << "3. �������������;" << endl;
					cout << "4. ����;" << endl;
					cout << "5. ���-��;" << endl;
					cout << "0. ������ ������." << endl;
					cout << ">>> "; cin >> choice;
					if (choice >= 1 && choice < numcol)
					{
						if (choice == 1)
						{
							cout << "������� ��������:   "; cin >> tname;
							count = PrintFind(columns[choice], tname);
						}
						if (choice == 2)
						{
							cout << "������� ��� ���������:   "; cin >> ttype;
							count = PrintFind(columns[choice], ttype);
						}
						if (choice == 3)
						{
							cout << "������� �������������:   "; cin >> tmaker;
							count = PrintFind(columns[choice], tmaker);
						}
						if (choice == 4)
						{
							cout << "������� ���� ��������:   "; cin >> tprice;
							count = PrintFind(columns[choice], tprice);
						}
						if (choice == 5)
						{
							cout << "������� ���-�� ��������:   "; cin >> tamount;
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
						cout << "������ �����! ������� ��� ���.";
						_getch();
						continue;
					}
					cout << "������� " << count << " �������." << endl;
				}
				else
				{
					cout << "������! ������� �����!";
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
					cout << endl << "�������� ������� �������:" << endl;
					cout << "1. ��������;" << endl;
					cout << "2. ���;" << endl;
					cout << "3. �������������;" << endl;
					cout << "4. ����;" << endl;
					cout << "5. ���-��;" << endl;
					cout << "0. ������ ����������." << endl;
					cout << ">>> "; cin >> choice;
					if (choice >= 1 && choice < numcol)
					{
						if (choice == 1)
						{
							cout << "������� ��������:   "; cin >> tname;
							count = PrintFilt(columns[choice], tname);
						}
						if (choice == 2)
						{
							cout << "������� ��� ���������:   "; cin >> ttype;
							count = PrintFilt(columns[choice], ttype);
						}
						if (choice == 3)
						{
							cout << "������� �������������:   "; cin >> tmaker;
							count = PrintFilt(columns[choice], tmaker);
						}
						if (choice == 4)
						{
							cout << "������� ���� ��������:   "; cin >> tprice;
							count = PrintFilt(columns[choice], tprice);
						}
						if (choice == 5)
						{
							cout << "������� ���-�� ��������:   "; cin >> tamount;
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
						cout << "������ �����! ������� ��� ���.";
						_getch();
						continue;
					}
					cout << "������� " << count << " �������." << endl;
				}
				else
				{
					cout << "������! ������� �����!";
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
					cout << endl << "�������� ������� �������:" << endl;
					cout << "1. ��������;" << endl;
					cout << "2. ���;" << endl;
					cout << "3. �������������;" << endl;
					cout << "4. ����;" << endl;
					cout << "5. ���-��;" << endl;
					cout << "0. ������ ����������." << endl;
					cout << ">>> "; cin >> choice;
					if (choice >= 1 && choice < numcol)
					{
						cout << "����������� ���������� �� �����������? (0-���, 1-��): ";
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
						cout << "������ �����! ������� ��� ���.";
						_getch();
						continue;
					}
					cout << "���������� " << (asc ? "�� �����������" : "�� ��������") << " ���������." << endl;
				}
				else
				{
					cout << "������! ������� �����!";
					_getch();
				}
				break;
			}
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "������ ����� �������!";
			_getch();
			break;
		}
	}
}
