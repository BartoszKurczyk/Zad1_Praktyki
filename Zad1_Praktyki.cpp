/*plik wsadowy musi mieć nazwę dane.txt. Dane muszą zostać wpisane pojedyńczo w każdej linii czyli np.:
4
5
6
A
G
H

a nie 
456AGH

Nie było określone w zadaniu jak ma wyglądać dokładnie plik wsadowy dlatego użyłem formy wygodniejszej dla mnie
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;
struct zamieniona
{
	unsigned char licz;
	string s;
};
struct liczba
{
	zamieniona licz;
	int liczjedynek;
};

string AF(unsigned char temp)
{
	if (temp == 10) return "A";
	else if (temp == 11) return "B";
	else if (temp == 12) return "C";
	else if (temp == 13) return "D";
	else if (temp == 14) return "E";
	else if (temp == 15) return "F";
	else return "Error";
}

vector<char> vec;
vector<char> odf;
vector<unsigned char> zam;
vector<zamieniona> skl;
vector<liczba> parz;
vector<liczba> nieparz;

bool wczytaj()
{
	
	ifstream plik;
	plik.open("dane.txt");
	if (!plik.good())
		return false;
	while (true)
	{
		char a;
		plik >> a;
		if (plik.good())
			vec.push_back(a);
		else
			break;
	}
	plik.close();
	return true;

}
void odfiltruj()
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if ((vec[i] >= 48 && vec[i] <= 57) || (vec[i] >= 65 && vec[i] <= 70))
		{
			odf.push_back(vec[i]);
		}
	}
	/*for (int i = 0; i < odf.size(); i++) {
		cout << odf[i] << endl;
	}*/
}
void zamiana()
{
	
	for (unsigned int i = 0; i < odf.size(); i++)
	{
		if (odf[i] == 48)
		{
			
			zam.push_back(0);
		}
		else if (odf[i] == 49)
		{
			zam.push_back(1);
		}
		else if (odf[i] == 50)
		{
			zam.push_back(2);
		}
		else if (odf[i] == 51)
		{
			zam.push_back(3);
		}
		else if (odf[i] == 52)
		{
			zam.push_back(4);
		}
		else if (odf[i] == 53)
		{
			zam.push_back(5);
		}
		else if (odf[i] == 54)
		{
			zam.push_back(6);
		}
		else if (odf[i] == 55)
		{
			zam.push_back(7);
		}
		else if (odf[i] == 56)
		{
			zam.push_back(8);
		}
		else if (odf[i] == 57)
		{
			zam.push_back(9);
		}
		else if (odf[i] == 65)
		{
			zam.push_back(10);
		}
		else if (odf[i] == 66)
		{
			zam.push_back(11);
		}
		else if (odf[i] == 67)
		{
			zam.push_back(12);
		}
		else if (odf[i] == 68)
		{
			zam.push_back(13);
		}
		else if (odf[i] == 69)
		{
			zam.push_back(14);
		}
		else if (odf[i] == 70)
		{
			zam.push_back(15);
		}
	}
}
void sklejanie()
{
	zamieniona sklejona;
	string str1, str2;
	int j;
	if (zam.size() % 2 == 0)
	{
		for (unsigned int i = 0; i < zam.size(); i = i + 2)
		{
			j = i + 1;
			sklejona.licz = zam[i] << 4;
			sklejona.licz |= zam[j];
			
			if (zam[i] >= 0 && zam[i] <= 9)
			{
				str1 = to_string(zam[i]);
			}
			else if (zam[i] >= 10 && zam[i] <= 15)
			{
				str1 = AF(zam[i]);
			}
			if (zam[j] >= 0 && zam[j] <= 9)
			{
				str2 = to_string(zam[j]);
			}
			else if (zam[j] >= 10 && zam[j] <= 15)
			{
				str2 = AF(zam[j]);
			}

			sklejona.s = str1 + str2;
			skl.push_back(sklejona);
		}
	}
	/*Nie było w prost powiedziane co zrobić jeśli wejsciowych elementów
	będzie nieparzysta ilość, więc zakładam że mają być przedstawione jak sklejenie 0 + ta liczba*/
	else
	{
		for (unsigned int i = 0; i < zam.size()-1; i = i + 2)
		{
			j = i + 1;
			sklejona.licz = zam[i] << 4;
			sklejona.licz |= zam[j];

			if (zam[i] >= 0 && zam[i] <= 9)
			{
				str1 = to_string(zam[i]);
			}
			else if (zam[i] >= 10 && zam[i] <= 15)
			{
				str1 = AF(zam[i]);
			}
			if (zam[j] >= 0 && zam[j] <= 9)
			{
				str2 = to_string(zam[j]);
			}
			else if (zam[j] >= 10 && zam[j] <= 15)
			{
				str2 = AF(zam[j]);
			}

			sklejona.s = str1 + str2;
			skl.push_back(sklejona);
		}
		sklejona.licz = zam[zam.size() - 1];
		str1 = to_string(0);
		if (zam[zam.size() - 1] >= 0 && zam[zam.size() - 1] <= 9)
		{
			str2 = to_string(zam[zam.size() - 1]);
		}
		else if (zam[zam.size() - 1] >= 10 && zam[zam.size() - 1] <= 15)
		{
			str2 = AF(zam[zam.size() - 1]);
		}

		sklejona.s = str1 + str2;
		skl.push_back(sklejona);
	}
}
void zliczanie()
{
	int licznik;
	liczba temp;
	for (unsigned int i = 0; i < skl.size(); i++)
	{
		licznik = 0;
		for (int j = 0; j < 8; j++)
		{
			if ((skl[i].licz >> j) & 1 == 1)
			{
				licznik++;
			}
		}
		temp.licz = skl[i];
		temp.liczjedynek = licznik;

		if (licznik % 2 == 0)
		{
			parz.push_back(temp);
		}
		else
		{
			nieparz.push_back(temp);
		}
	}
}
void sort()
{
	int flag1, flag2;
	liczba temp1, temp2;
#pragma region sort_parzyste
	
	for (unsigned int i = 0; i < parz.size(); i++)
	{
		flag1 = 0;
		for (unsigned int j = 0; j < parz.size() - i - 1; j++)
		{
			if (parz[j].liczjedynek > parz[j+1].liczjedynek)
			{
				temp1 = parz[j + 1];
				parz[j + 1] = parz[j];
				parz[j] = temp1;
				flag1 = 1;
			}
		}
		if (flag1 == 0)
			break;

	}

#pragma endregion
#pragma region sort_nieparzyste
	for (unsigned int i = 0; i < nieparz.size(); i++)
	{
		flag2 = 0;
		for (unsigned int j = 0; j < nieparz.size() - i - 1; j++)
		{
			if (nieparz[j].liczjedynek < nieparz[j + 1].liczjedynek)
			{
				temp2 = nieparz[j + 1];
				nieparz[j + 1] = nieparz[j];
				nieparz[j] = temp2;
				flag2 = 1;
			}
		}
		if (flag2 == 0)
			break;

	}
#pragma endregion

}
bool zapisz()
{
	string s = "xd";
	ofstream plik1;
	plik1.open("out.txt");
	if (!plik1.good())
		return false;
	
	
		
	if (plik1.good())
	{
		for (unsigned int i = 0; i < parz.size(); i++)
		{
			plik1 << parz[i].licz.s << endl;
		}
		for (unsigned int i = 0; i < nieparz.size(); i++)
		{
			plik1 << nieparz[i].licz.s << endl;
		}
	}
		
	
	plik1.close();
	return true;

}
int main()
{
	
	if (!wczytaj()) {
		std::cout << "Wczytanie nie powiodlo sie" << endl;
	}
	odfiltruj();
	zamiana();
	sklejanie();

	/*for (int i = 0; i < skl.size(); i++)
	{
		cout << skl[i].s << endl;
	}*/
	zliczanie();
	std::cout << "Parzyste" << endl;
	for (unsigned int i = 0; i < parz.size(); i++)
	{
		std::cout << parz[i].licz.s << endl;
	}
	std::cout << "Nieparzyste" << endl;
	for (unsigned int i = 0; i < nieparz.size(); i++)
	{
		std::cout << nieparz[i].licz.s << endl;
	}

	sort();
	std::cout << "Po sortowaniu" << endl;
	std::cout << "Parzyste" << endl;
	for (unsigned int i = 0; i < parz.size(); i++)
	{
		std::cout << parz[i].licz.s << endl;
	}
	std::cout << "Nieparzyste" << endl;
	for (unsigned int i = 0; i < nieparz.size(); i++)
	{
		std::cout << nieparz[i].licz.s << endl;
	}
	zapisz();
	vec.clear(); 
	odf.clear();
	zam.clear();
	skl.clear();;
	parz.clear();
	nieparz.clear();

    return 0;
}

