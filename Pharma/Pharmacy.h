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
	//���������� ����� ��������� 
	vector<int> id;
	//������������ ���������
	vector<string> name;
	//������������� ����� ���������
	vector<string> type;
	//������������� ���������
	vector<string> maker;
	//��������� ���������
	vector<double> price;
	//����������� ����
	vector<int> amount;

	int nextid = 0;
	//��� �����, � ������� ����������� ������
	string filename = "data.txt";
	//���-�� �������� �������
	static const int numcol = 6;
	//������ ����-���������� �������� �������
	const string columns[numcol] = { "ID", "��������", "���", "�������������", "����", "���-��" };
	//���������� �������� �� ������ ������� (���-�� �������� ��� ������������ �� �������� ����������� ������)
	static const int vertical = 9;
	//����������� ����� ����� �������
	string horizontal = string(vertical * 2 * numcol - (vertical % 2 == 0 ? vertical / 2 - 1 : vertical / 2), '-');

	//������������ ��������� � ��������� �������
	void CreateTable();
	
	void SaveTxt();
	
	//����� �� ����� � ���������� � ��������� ����
	void Print();
	
	//����� �� ������� � ����� � �����
	int PrintFind(string column, string key);
	
	int PrintFind(string column, double key);
	
	int PrintFind(string column, int key);
	
	//���������� �� ������� � ����� � �����
	int PrintFilt(string column, string key);
	
	int PrintFilt(string column, double key);
	
	int PrintFilt(string column, int key);
	
	//���������� �� ������ � ����� � �����
	void PrintSort(string column, bool asc = true);
	
	void SortTable(vector<string> v, bool asc = true);
	
	void SortTable(vector<double> v, bool asc = true);
	
	void SortTable(vector<int> v, bool asc = true);
	
	//���������� ����� ������ � �����
	void Create(string name, string type, string maker, double price, int amount);
	
	void Create(int id, string name, string type, string maker, double price, int amount);
	
	//�������� ������ �� id
	void Delete(int id);
	
	//���������� ������ �� id
	void Update(int id, string name = "", string type = "", string maker = "", double price = 0.0, int amount = 0);
	
	//��������� ���� data �� ����������
	ofstream WriteOpen();
	
	//��������� ���� data �� ��������
	ofstream UpdateOpen();
	
	//��������� ���� ��� ������ � �������
	ifstream ReadOpen();
	
	//������ ������ � ����� ��� ������ � �������
	void ReadFile();
	
public:
	Pharmacy();
	
	Pharmacy(string filename);
	
	Pharmacy(string name, string type, string maker, double price, int amount);
	
	Pharmacy(int id, string name, string type, string maker, double price, int amount);
	
	void menu();
	
};

