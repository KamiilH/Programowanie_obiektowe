#include "samochod.h"
using namespace std;

	fstream plik;// uzywane w funkcji "wczytaj" i "zapisz"
	int x;// uzywane w funkcji "usun"
	int temp3 = -1; //uzywane w funkcji "po_parametrach"
	int p; //uzyw. w c1 "po_parametrach", 
	short int t; //uzyw. w c4., c5., c6. "po_parametrach"
	float g; // uzyw w c2. c3. "po_parametrach"
	string e; // uzyw w c9. c.10 w "po_parametrach"
	int temp2; //uzyw w "posortowane"


samochod* wczytaj(int* i)
{
	//fstream plik;
	plik.open("katalog2.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Blad otwarcia pliku." << endl;
		exit(-1);
	}
	plik >> *i; //pobranie iloœci samochodow w katalogu
	samochod* kat = new samochod[*i];
	for (int j = 0; j < *i; j++) 
	{
		plik >> kat[j].marka;
		plik >> kat[j].model;
		plik >> kat[j].rocznik;
		plik >> kat[j].pojemnosc;
		plik >> kat[j].moc;
		plik >> kat[j].przebieg;
		plik >> kat[j].skrzynia;
	}
	plik.close();
	return kat;
}
void zapisz(int i, samochod kat[])
{
	//fstream plik;
	plik.open("katalog2.txt", ios::out);
	if (plik.good() == false)
	{
		cout << "Blad otwarcia pliku." << endl;
		exit(-1);
	}
	plik << i << endl; //pobranie iloœci samochodow w katalogu
	for (int j = 0; j < i; j++)
	{
		plik << kat[j].marka << " ";
		plik << kat[j].model << " ";
		plik << kat[j].rocznik << " ";
		plik << kat[j].pojemnosc << " ";
		plik << kat[j].moc << " ";
		plik << kat[j].przebieg << " ";
		plik << kat[j].skrzynia;
		plik << endl;
	}
	plik.close();
}
samochod* dodaj(int* i, samochod kat[])
{
	samochod* nowa = powieksz(*i, kat);	//zwiekszyc tablice o 1
	cin >> nowa[*i];	//wczytac >> od uzytkownika
	*i = *i + 1;	//zwiekszyc i o 1
	return nowa;
}
samochod* powieksz(int i, samochod kat[])
{
	samochod* nowa = new samochod[i + 1];
	for (int j = 0; j < i; j++)
	{
		nowa[j].marka = kat[j].marka;
		nowa[j].model = kat[j].model;
		nowa[j].rocznik = kat[j].rocznik;
		nowa[j].pojemnosc = kat[j].pojemnosc;
		nowa[j].moc = kat[j].moc;
		nowa[j].przebieg = kat[j].przebieg;
		nowa[j].skrzynia = kat[j].skrzynia;
	}
	delete[]kat;
	return nowa;
}
istream& operator>> (istream& wejscie, samochod& n)
{
	cout << "Marka: "; wejscie >> n.marka;
	cout << "Model: "; wejscie >> n.model;
	cout << "Rocznik: "; wejscie >> n.rocznik;
	cout << "Pojemnsc (w litrach): "; wejscie >> n.pojemnosc;
	cout << "Moc (w KM) : "; wejscie >> n.moc;
	cout << "Przebieg: "; wejscie >> n.przebieg;
	cout << "Skrzynia biegow (\"0\" - automatyczna, \"1\" - manualna):  "; wejscie >> n.skrzynia;
	return wejscie;
}
samochod* usun(int* i, samochod kat[])
{
	//int x;
	cout << "Samochod o jakim numerze chcesz usunac? Nr: "; cin >> x;
	if (x > * i)
	{
		cout << "Nie ma samochodu o takim numerze!" << endl;
	}
	else if (*i	 >= x)
	{
		samochod* nowa = new samochod[*i - 1];
		for (int j = 0; j < *i-1; j++)
		{
			if (x > j)
			{
				nowa[j].marka = kat[j].marka;
				nowa[j].model = kat[j].model;
				nowa[j].rocznik = kat[j].rocznik;
				nowa[j].pojemnosc = kat[j].pojemnosc;
				nowa[j].moc = kat[j].moc;
				nowa[j].przebieg = kat[j].przebieg;
				nowa[j].skrzynia = kat[j].skrzynia;
			}
			else
			{
				nowa[j].marka = kat[j + 1].marka;
				nowa[j].model = kat[j + 1].model;
				nowa[j].rocznik = kat[j + 1].rocznik;
				nowa[j].pojemnosc = kat[j + 1].pojemnosc;
				nowa[j].moc = kat[j + 1].moc;
				nowa[j].przebieg = kat[j + 1].przebieg;
				nowa[j].skrzynia = kat[j + 1].skrzynia;
			}
		}
		delete[]kat;
		return nowa;
	}
	return kat;
}
samochod* zmniejsz(int* i, samochod kat[])
{
	samochod* nowa = usun(i, kat);
	*i = *i - 1;
	return nowa;
}
/////////////////////////////////////////////////////////
void wypis_wszystkich(int i, samochod kat[])
{
	for (int j = 0; i>j; j++)
	{
		cout << "nr: " << j << endl;
		cout << "Marka: " <<kat[j].marka << endl;
		cout << "Model: " << kat[j].model << endl;
		cout << "Rocznk: " << kat[j].rocznik << endl;
		cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
		cout << "Moc: " << kat[j].moc << endl;
		cout << "Przebieg: " << kat[j].przebieg << endl;
		if (kat[j].skrzynia == 1)
			cout << "Skrzynia: Manualna" << endl << endl;
		else
			cout << "Skrzynia: Automatyczna" << endl << endl;
	}
}
void po_parametrach(int i, samochod kat[])
{
//int temp3=-1;
while (temp3 != 0)
{
	{
	cout << "1. Przebieg ponizej okreslonej wartosci." << endl;
	cout << "2. Pojemnosc silnika ponizej okreslonej wartosci." << endl;
	cout << "3. Pojemnosc silnika powyzej okreslonej wartosci." << endl;
	cout << "4. Moc powyzej okreslonej wartosci." << endl;
	cout << "5. Rocznik ponizej okreslonej wartosci." << endl;
	cout << "6. Rocznik powyzej okreslonej wartosci." << endl;
	cout << "7. Samochody z automatyczna skrzynia biegow." << endl;
	cout << "8. Samochody z manualna skrzynia biegow." << endl;
	cout << "9. Okreslona marka samochodu." << endl;
	cout << "10. Okreslony model samochodu." << endl; 
	cout << "0. Powrot do MENU." << endl;
	cout << "Wybieram numer: "; cin >> temp3;
	system("cls");
	} 
		//couty do wyboru
	switch (temp3)
	{
	case 1:
	{
		//int p;
		cout << "Maksymalny przebieg to: "; cin >> p;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].przebieg <= p)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 2:
	{
		// float p; zastapiony przez float g 
		cout << "Maksymalna pojemnosc silnika: "; cin >> g;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].pojemnosc <= g)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 3:
	{
		//float p; //zastapione przez float g
		cout << "Minimalna pojemnosc silnika: "; cin >> g;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].pojemnosc >= g)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 4:
	{
		//short int p; //zastapione short int t
		cout << "Minimalna moc silnika: "; cin >> t;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].moc >= t)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 5:
	{
		//short int p; //zastapione short int t
		cout << "Maksymalny rok wyprodukowania: "; cin >> t;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].rocznik <= t)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 6:
	{
		//short int p; //zastapione short int t
		cout << "Minimalny rok wyprodukowania: "; cin >> t;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].rocznik >= t)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 7:
	{
		for (int j = 0; j < i; j++)
		{
			if (kat[j].skrzynia == 0)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 8:
	{
		for (int j = 0; j < i; j++)
		{
			if (kat[j].skrzynia == 1)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 9:
	{
		//string p; //zastapione przez string e
		cout << "Marka samochodu: "; cin >> e;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].marka == e)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	case 10:
	{
		//string p; // zast przez string e
		cout << "Model samochodu: "; cin >> e;
		for (int j = 0; j < i; j++)
		{
			if (kat[j].model == e)
			{
				cout << "Marka: " << kat[j].marka << endl;
				cout << "Model: " << kat[j].model << endl;
				cout << "Rocznk: " << kat[j].rocznik << endl;
				cout << "Pojemnosc: " << kat[j].pojemnosc << endl;
				cout << "Moc: " << kat[j].moc << endl;
				cout << "Przebieg: " << kat[j].przebieg << endl;
				if (kat[j].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
		}
		break;
	}
	}
}
}
void posortowane(int i, samochod kat[])
{
	//int temp2;
	cout << "1. Sortowanie po przebiegu." << endl;
	cout << "2. Sortowanie po pojemnosci silnika." << endl;
	cout << "3. Sortowanie po ilosci konii mechanicznych." << endl;
	cout << "4. Sortowanie po roku produkcji." << endl;
	cout << "Wybieram opcje: "; cin >> temp2;
	system("cls");
	quick_sort(kat, 0, i - 1, temp2);
	
}
void quick_sort(samochod tab[], int lewy, int prawy, int par)
{
	switch (par)
	{
	case 1:
	{
		if (prawy <= lewy) return;

		int i = lewy - 1, j = prawy + 1,
			srodek = tab[(lewy + prawy) / 2].przebieg; //punkt œrodkowy

		while (1)
		{
			//element wiêkszy od œrodkowego na prawo
			while (srodek > tab[++i].przebieg);

			//element mniejszy na prawo od œrodkowego
			while (srodek < tab[--j].przebieg);

			//jesli liczniki sie nie minely to zamieñ elementy ze soba
			//stojace po niewlasciwej stronie elementu pivot
			if (i <= j)

				swap(tab,i,j);
			else
				break;
		}
		if (j > lewy)
			quick_sort(tab, lewy, j, par);
		if (i < prawy)
			quick_sort(tab, i, prawy, par);

		break;
	}
	case 2:
	{
		if (prawy <= lewy) return;

		int i = lewy - 1, j = prawy + 1,
			srodek = tab[(lewy + prawy) / 2].pojemnosc; //punkt œrodkowy

		while (1)
		{
			//element wiêkszy od œrodkowego na prawo
			while (srodek > tab[++i].pojemnosc);

			//element mniejszy na prawo od œrodkowego
			while (srodek < tab[--j].pojemnosc);

			//jesli liczniki sie nie minely to zamieñ elementy ze soba
			//stojace po niewlasciwej stronie elementu pivot
			if (i <= j)

				swap(tab, i, j);
			else
				break;
		}
		if (j > lewy)
			quick_sort(tab, lewy, j, par);
		if (i < prawy)
			quick_sort(tab, i, prawy, par);
		break;
	}
	case 3:
	{
		if (prawy <= lewy) return;

		int i = lewy - 1, j = prawy + 1,
			srodek = tab[(lewy + prawy) / 2].moc; //punkt œrodkowy

		while (1)
		{
			//element wiêkszy od œrodkowego na prawo
			while (srodek > tab[++i].moc);

			//element mniejszy na prawo od œrodkowego
			while (srodek < tab[--j].moc);

			//jesli liczniki sie nie minely to zamieñ elementy ze soba
			//stojace po niewlasciwej stronie elementu pivot
			if (i <= j)

				swap(tab, i, j);
			else
				break;
		}
		if (j > lewy)
			quick_sort(tab, lewy, j, par);
		if (i < prawy)
			quick_sort(tab, i, prawy, par);
		break;
	}
	case 4:
	{
		if (prawy <= lewy) return;

		int i = lewy - 1, j = prawy + 1,
			srodek = tab[(lewy + prawy) / 2].rocznik; //punkt œrodkowy

		while (1)
		{
			//element wiêkszy od œrodkowego na prawo
			while (srodek > tab[++i].rocznik);

			//element mniejszy na prawo od œrodkowego
			while (srodek < tab[--j].rocznik);

			//jesli liczniki sie nie minely to zamieñ elementy ze soba
			//stojace po niewlasciwej stronie elementu pivot
			if (i <= j)

				swap(tab, i, j);
			else
				break;
		}
		if (j > lewy)
			quick_sort(tab, lewy, j, par);
		if (i < prawy)
			quick_sort(tab, i, prawy, par);
		break;
	}
	default:
		cout << "Wpisano nie poprawny znak!" << endl;
	}
}
void swap(samochod tablica[], int i, int j)
{
	samochod tmp = tablica[i];
	tablica[i] = tablica[j];
	tablica[j] = tmp;

}