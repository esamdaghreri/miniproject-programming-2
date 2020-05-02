//
//  Created by Esam Ali Yahya Daghreri on 25/11/2017.
//  Copyright © 2019 Esam. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
using namespace std;
void AddRecord(int, string, string, double);
void ShowRecords();
void SearchRecord();
void Edit();
void DeleTE();



string fn; string ls; int id = 0; double meony = 0; int a;


int main() {
	int x;
	fstream file;
	while (true)
	{
		cout << "-=-=-=-=-=-=-=-=-=-= Account information system =-=-=-=-=-=-=-=-=-=-" << endl;
		cout << "Select one of thies option below." << endl;
		cout << "     1-> Add new record to file." << endl;
		cout << "     2-> Show record from file." << endl;
		cout << "     3-> search record from ID." << endl;
		cout << "     4-> Edit record." << endl;
		cout << "     5-> Delete record." << endl;
		cout << "     0-> quit " << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Enter your ID" << endl;
			cin >> id;
			cout << "Enter your first name" << endl;
			cin >> fn;
			cout << "Enter your last name" << endl;
			cin >> ls;
			cout << "Enter your balance" << endl;
			cin >> meony;
			AddRecord(id, fn, ls, meony);
			break;
		case 2:
			ShowRecords();
			break;
		case 3:
			SearchRecord();
			break;
		case 4:
			Edit();
			break;
		case 5:
			DeleTE();
			break;

		case 0:
			cout << "exit from program" << endl;
			exit(0);

			break;
		default:cout << "Wrong choice" << endl;

		}
	}


	return 0;

}




void AddRecord(int id, string fn, string ls, double meony)
{


	fstream file;


	file.open("BankAccound.txt", ios::app);
	if (!file.is_open())
	{
		cout << "file not open" << endl;
		exit(1);
	}
	else {
		file << id << "  " << fn << "  " << ls << "  " << meony << endl;
		cout << "information save it on the file" << endl;
		file.close();
		exit(1);
	}

}




void ShowRecords() {
	ifstream file("BankAccound.txt");
	if (!file.is_open())
	{
		cout << "file not open" << endl;
		exit(2);
	}
	else {
		while (file >> id >> fn >> ls >> meony) {
			cout << "ID= " << id << ", " << "First name " << fn << ", " << "Last name " << ls << ", " << "balance " << meony << endl;

		}
		file.close();

	}

}


void SearchRecord() {
	int search;
	ifstream file("BankAccound.txt");
	cout << "Type the ID you want to search" << endl;
	cin >> search;
	while (file >> id >> fn >> ls >> meony) {
		if (id == search) {
			cout << "ID= " << id << ", " << "First name " << fn << ", " << "Last name " << ls << ", " << "  balance " << meony << endl;
		}
	}
}






void Edit() {
	int id; string fn; string ls; double meony; int ID; int nid;  string nfn; string nls; double nmeony;
	fstream file;
	ifstream file1;

	cout << "Type the ID you want to edit it" << endl;
	cin >> ID;
	nid = ID;
	file.open("Temp.txt", ios::app);
	if (!file.is_open())
	{
		cout << "file not open" << endl;
		exit(3);
	}
	else {
		ifstream file1("BankAccound.txt");
		while (file1 >> id >> fn >> ls >> meony) {
			if (id == ID) {
				cout << "ID= " << id << ", " << "First name " << fn << ", " << "Last name " << ls << ", " << "  balance " << meony << endl;
				cout << "     1-> Edit first name." << endl;
				cout << "     2-> Edit last name." << endl;
				cout << "     3-> Edit the balance" << endl;
				cin >> a;
				switch (a) {
				case 1:
					cout << "enter the new first name" << endl;
					cin >> nfn;
					file << nid << "  " << nfn << "  " << ls << "  " << meony << endl;
					break;
				case 2:
					cout << "enter the new last name" << endl;
					cin >> nls;
					file << nid << "  " << fn << "  " << nls << "  " << meony << endl;
					break;
				case 3:
					cout << "enter the new balance" << endl;
					cin >> nmeony;
					file << nid << "  " << fn << "  " << ls << "  " << nmeony << endl;
					break;
				}
			}
			else {
				file << id << "  " << fn << "  " << ls << "  " << meony << endl;
			}
		}
	}
	file.close();
	file1.close();
	remove("BankAccound.txt");
	rename("Temp.txt", "BankAccound.txt");

}








void DeleTE() {
	int id; string fn; string ls; double meony; int ID;
	fstream file;
	ifstream file1;
	cout << "Type the ID you want to delete it" << endl;
	cin >> ID;
	file.open("Temp.txt", ios::app);
	if (!file.is_open())
	{
		cout << "file not open" << endl;
		exit(1);
	}
	else {
		ifstream file1("BankAccound.txt");
		while (file1 >> id >> fn >> ls >> meony) {
			if (id == ID) {
				cout << "ID= " << id << ", " << "First name " << fn << ", " << "Last name " << ls << ", " << "  balance " << meony << endl;
				cout << "this account has been delete" << endl;
			}
			else {
				file << id << "  " << fn << "  " << ls << "  " << meony << endl;
			}
		}
	}
	file.close();
	file1.close();
	remove("BankAccound.txt");
	rename("Temp.txt", "BankAccound.txt");

}