#include "samochod.h"

using namespace std;

int main()
{
	short int menu_nr=-1;
	short int tmp;
	int l = -1; //iloœæ elementów w katalogu
	samochod* katalog = new samochod;
	while (menu_nr != 0)
	{
		cout << "MENU" << endl;
		cout << "1. Wyswietl katalog wszystkich samochodow." << endl;
		cout << "2. Wyswietl dane jednego samochodu." << endl;
		cout << "3. Wyswietl liste samochodow posortowana wedlug:" << endl;
		cout << "4. Wyswietl liste z samochodami spelniajacymi wytyczne: " << endl;
		cout << "5. Dodaj nowy samochod do katalogu." << endl;
		cout << "6. Usun samochod z katalogu." << endl;
		cout << "7. Wczytaj z pliku" << endl;
		cout << "8. Zapisz do pliku" << endl;
		cout << "0. Koniec programu" << endl;
		cout << "Wybieram pozycje: "; cin >> menu_nr;
		system("cls");
		switch (menu_nr)
		{
		case 1:
		{
			wypis_wszystkich(l, katalog);
			system("PAUSE");
			system("cls");
			break;
		}
		case 2:
		{
			cout << "Chcesz zobaczyc dane samochodu o numerze: "; cin >> tmp; cout << endl;
			if (tmp > l)
			{
				cout << "Wpisano za duzy numer." << endl;
			}
			else
			{
				cout << "Marka: " << katalog[tmp].marka << endl;
				cout << "Model: " << katalog[tmp].model << endl;
				cout << "Rocznk: " << katalog[tmp].rocznik << endl;
				cout << "Pojemnosc: " << katalog[tmp].pojemnosc << endl;
				cout << "Moc: " << katalog[tmp].moc << endl;
				cout << "Przebieg: " << katalog[tmp].przebieg << endl;
				if (katalog[tmp].skrzynia == 1)
					cout << "Skrzynia: Manualna" << endl << endl;
				else
					cout << "Skrzynia: Automatyczna" << endl << endl;
			}
			system("PAUSE");
			system("cls");
			break;
		}
		case 3:
		{
			if (l <= 0)
			{
				cout << "Nie mam co wyswietlic." << endl;
			}
			else
			{
				posortowane(l, katalog);
				wypis_wszystkich(l, katalog);
				system("PAUSE");
				system("cls");
			}
			break;
		}
		case 4:
		{
			if (l <= 0)
			{
				cout << "Nie mam co wyswietlic." << endl;
			}
			else
			{
				po_parametrach(l, katalog);
			}
			break;
		}
		case 5:
		{
			if (l < 0)
			{
				l = 0; //bo bez wczytania l=-1
			}
			katalog = dodaj(&l, katalog);
			break;
		}
		case 6:
		{
			katalog = zmniejsz(&l, katalog);
			break;
		}
		case 7:
		{
			katalog = wczytaj(&l);//laduje dane z pliku .txt (bez tego uzywamy tylko tego co jest w RAM, czyli na poczatku jest pusto)
			break;
		}
		case 8:
		{
			if ( l<=0)
			{
				cout << "Nie ma co zapisaæ" << endl;
			}
			else
			{
				zapisz(l, katalog);	//zapisujemy to co zmienilismy w katalogu
			}
			break;
		}
		default:
			cout << "Wpisano nie poprawny znak." << endl;
			break;
		}
	}
	return 0;
}