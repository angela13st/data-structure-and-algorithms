#include <iostream>
#include <string>
#include <time.h>
#include "funkcije.h"
#include<vector>
using namespace std;

void razmaci(string& recenica)
{
	for (int i = 0; i < recenica.size(); i++)
	{
		if ((recenica[i] == '.' || recenica[i] == ',' || recenica[i] == '!' || recenica[i] == '?') && recenica[i - 1] == ' ')
		{
			recenica.erase(i - 1, 1);
		}


	}
	for (int i = 0; i < recenica.size(); i++)
	{
		if ((recenica[i] == '.' || recenica[i] == ',' || recenica[i] == '!' || recenica[i] == '?') && recenica[i + 1] != ' ')
		{
			recenica.insert(i + 1, " ");
		}
	}

}

void piglatin(vector<string>pig,int random)
{
	string str2;
	string str1 = pig[random];
	size_t a = 0;
	int i = 0;
	while (!str1.empty())
	{
		a = str1.find(" ");
		str2 = str1.substr(0, a);
		if (str2[0] == 'a' || str2[0] == 'e' || str2[0] == 'i' || str2[0] == '0' || str2[0] == 'u')
		{
			
			if (a == str1.npos)
				str1.clear();
			else
				str1.erase(0, a + 1);			
		
			str2 = str2 + "hay";


			
		}
	 	else
		{
			
			while (!str2.empty() && (str2[i] != 'a' && str2[i] != 'e' && str2[i] != 'i' && str2[i] != 'o' && str2[i] == 'u'))
			{
				
				i++;
			}

			
			if (a == str1.npos)
				str1.clear();
			else
				str1.erase(0, a + 1 + i);
			
			str2 = str2 + str2.at(0);
			str2 = str2 + "ay";
			
			str2.erase(0, i+1);
			
		}
		cout << " " << str2;
		

		str2.clear();
		
	}
	cout << endl;
	
}

void playmatches(vector<int> matches)
{
	srand(time(NULL));
	int uzima = 1;
	while (matches.size() <= 20)

	{
		cout << "Sibica u igri: " << 21 - matches.size() << "\n";
		uzima = rand() % (3 - 1 + 1) + 1;
		if (matches.size() == 17)
		{
			cout << "CPU je uzeo 3 \n";
			for (int i = 0; i < 3; i++)
			{
				matches.push_back(1);
			}
		}
		else if (matches.size() == 18)
		{
			cout << "CPU je uzeo 2 \n";
			for (int i = 0; i < 2; i++)
			{
				matches.push_back(1);
			}
		}
		else if (matches.size() == 19)
		{
			
			cout << "CPU je uzeo 1 \n";
			matches.push_back(1);

		}
		else if (matches.size() == 20)
		{
			cout << "CPU je izgubio \n";
			exit(0);
		}
		else
		{
			cout << "CPU je uzeo " << uzima << " \n";
			for (int i = 0; i < uzima; i++)
			{
				matches.push_back(1);
			}
		}
		if (matches.size() == 20)
		{
			cout << "Igrac je izgubio \n";
			exit(0);
		}
		cout << "Sibica u igri: " << 21 - matches.size() << " \n";
		cout << "igrac uzima: ";
		cin >> uzima;
		while ((uzima < 1 || uzima>3) && uzima > 21 - matches.size())
		{
			if (21 - matches.size() < 3)
			{
				cout << "mozete uzeti najvise " << 21 - matches.size() << "sibica\n";
			}
			cout << "igrac uzima: ";
			cin >> uzima;
		}
		for (int i = 0; i < uzima; i++)
		{
			matches.push_back(1);
		}
	}
}

void stuffing_bit1(vector<int> &bin)
{
	int c=0;
	vector<int>::iterator it;
	it = bin.begin();
	for (int i = 0; i < bin.size(); i++)
	{
		if (bin[i] == 1)
		{
			c++;

			if (c == 5)
			{
				bin.insert(it + i + 1, 0);
			}
		}
		else
			c = 0;
	}
}
void unstuffing_bit1(vector<int>& bin)
{
	int c = 0;
	vector<int>::iterator it;
	it = bin.begin();
	for (int i = 0; i < bin.size(); i++)
	{
		if (bin[i] == 1)
		{
			c++;

			if (c == 5)
			{
				bin.erase(it + i + 1);
			}
		}
		else
			c = 0;
	}
}