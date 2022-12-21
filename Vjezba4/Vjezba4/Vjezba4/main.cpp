#include <iostream>
#include <string>
#include "funkcije.h"
#include<vector>
using namespace std;


int main()
{
	//zad1
	/*
	string recenica;
	getline(cin, recenica);
	razmaci(recenica);
	cout << recenica;
	*/

	//zad2
	
	int n = 0;
	vector<string> pig;
	cout << "koliko recenica zelite unijeti?";
	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cout << "unesi recenicu: ";
		cin.ignore(1, '\n');

		getline(cin, tmp);
		pig.push_back(tmp);
	}
	
	int random = rand() % n;
	piglatin(pig, random);
	

	//zad3
	/*
	vector<int>bin;
	int z;
	cout << "unesi znamenku 0/1:";
	cin >> z;
	while (z == 0 || z == 1)
	{
		bin.push_back(z);
		cout << "unesi znamenku 0/1:";
		cin >> z;
	}

	for (int i = 0; i < bin.size(); i++)
	{
		cout << bin[i];
	}
	stuffing_bit1(bin);
	cout << "\n";
	for (int i = 0; i < bin.size(); i++)
	{
		cout << bin[i];
	}
	unstuffing_bit1(bin);
	cout << "\n";
	for (int i = 0; i < bin.size(); i++)
	{
		cout << bin[i];
	}
	*/

	//zad5
	/*
	vector<int> matches(0);
	playmatches(matches);
	*/

	return 0;
	
}