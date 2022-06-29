#include "Menu.h"
#include "Macierz.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <stdexcept>

void Menu::open()
{
	std::vector <std::string> tablica;

	system("cls"); //czyszczenie okna konsoli

	std::cout << "Kalkulator macierzy\n";
	std::cout << "Wybierz opcje numerem na klawiaturze:\n";
	std::cout << "1. Wprowadzenie macierzy A\n";
	std::cout << "2. Wprowadzenie macierzy B\n";
	std::cout << "3. Dodawanie macierzy\n";
	std::cout << "4. Odejmowanie macierzy\n";
	std::cout << "5. Mnozenie macierzy\n";
	std::cout << "6. Wyznacznik macierzy\n";
	std::cout << "7. Transponowanie macierzy\n";
	std::cout << "0. Zamknij program\n";

	switch (_getch())
	{
	case '0':	//Zakonczenie programu
	{
		exit(1);
	}
	case '1':	//Wprowadzenie macierzy A
	{
		tablica.clear();
		tablica = wprowadzenie();
		Mac_A.usun();

		if (typ(tablica))
		{
			Mac_A.zapis(stworz<double>(tablica));
		}
		if (!typ(tablica))
		{
			Mac_A.zapis(stworz<int>(tablica));
		}

		ENTER_continue();
		break;
	}
	case '2':	//Wprowadzenie macierzy B
	{
		tablica.clear();
		tablica = wprowadzenie();
		Mac_B.usun();

		if (typ(tablica))
		{
			Mac_B.zapis(stworz<double>(tablica));
		}
		if (!typ(tablica))
		{
			Mac_B.zapis(stworz<int>(tablica));
		}
		ENTER_continue();
		break;
	}
	case '3':	//Dodawanie
	{
		Macierz wynik;
		system("cls");
		std::cout << "Macierz wynikowa A+B:" << std::endl;
		if (Mac_A.size_x() == Mac_B.size_x() && Mac_A.size_y() == Mac_B.size_y())
		{
			wynik = Mac_A + Mac_B;
			wynik.size_set(Mac_A.size_x(), Mac_A.size_y());
			wynik.show();
			wpis(wynik);
		}
		else
		{
			std::cout << "ERROR: Macierze nie sa rownej wielkosci" << std::endl;
		}

		ENTER_continue();
		break;
	}
	case '4':	//Odejmowanie
	{
		Macierz wynik;
		system("cls");
		if (Mac_A.size_x() == Mac_B.size_x() && Mac_A.size_y() == Mac_B.size_y())
		{
			std::cout << "Wybor dzialania:" << std::endl;
			std::cout << "1.Wynik A-B" << std::endl;
			std::cout << "2.Wynik B-A" << std::endl;
			switch (_getch())
			{
			case '1':
				system("cls");
				std::cout << "Macierz wynikowa:" << std::endl;
				wynik = Mac_A - Mac_B;
				wynik.size_set(Mac_A.size_x(), Mac_A.size_y());
				wynik.show();
				wpis(wynik);
				break;
			case '2':
				system("cls");
				std::cout << "Macierz wynikowa:" << std::endl;
				wynik = Mac_B - Mac_A;
				wynik.size_set(Mac_A.size_x(), Mac_A.size_y());
				wynik.show();
				wpis(wynik);
				break;
			}
		}
		else
		{
			std::cout << "ERROR: Macierze nie sa rownej wielkosci" << std::endl;
		}
		ENTER_continue();
		break;
	}
	case '5':	//Mnozenie
	{
		Macierz wynik;
		system("cls");
		std::cout << "Wybierz typ mnozenia:" << std::endl;
		std::cout << "1.Mnozenie przez liczbe" << std::endl;
		std::cout << "2.Mnozenie przez macierz" << std::endl;
		switch (_getch())
		{
		case '1':
			system("cls");
			double liczba;
			std::cout << "Wybierz macierz do pomnozenia" << std::endl;
			std::cout << "1.Macierz A" << std::endl;
			std::cout << "2.Macierz B" << std::endl;
			switch (_getch())
			{
			case '1':
				system("cls");
				std::cout << "Podaj liczbe przez ktora pomnozyc:";
				std::cin >> liczba;
				wynik.size_set(Mac_A.size_x(), Mac_A.size_y());
				wynik = Mac_A * liczba;
				wynik.show();
				wpis(wynik);
				break;
			case '2':
				system("cls");
				std::cout << "Podaj liczbe przez ktora pomnozyc:";
				std::cin >> liczba;
				wynik.size_set(Mac_B.size_x(), Mac_B.size_y());
				wynik = Mac_B * liczba;
				wynik.show();
				wpis(wynik);
				break;
			}
			break;
		case '2':
			system("cls");
			std::cout << "Macierz wynikowa AxB" << std::endl;
			if (Mac_A.size_x() != Mac_B.size_x())
			{
				std::cout << "Nie mozna pomnozyc macierzy!";
			}
			else
			{
				wynik = Mac_A * Mac_B;
				wynik.size_set(Mac_A.size_x(), Mac_A.size_y());
				wynik.show();
				wpis(wynik);
			}
			break;
		}
		ENTER_continue();
		break;
	}
	case '6':	//Wyznacznik macierzy
	{
		system("cls");
		std::cout << "Wybierz macierz, aby oblicznyc wyznacznik:" << std::endl;
		std::cout << "1.Macierz A" << std::endl;
		std::cout << "2.Macierz B" << std::endl;
		switch (_getch())
		{
		case '1':
			if (Mac_A.size_x() != Mac_A.size_y())
			{
				std::cout << "Aby obliczyc wyznacznik, podaj macierz kwadratowa" << std::endl;
			}
			else
			{
				system("cls");
				printf("det(A) = %3.2f\n", Mac_A.wyznacznik(Mac_A.size_x(), Mac_A.stereo()));
			}
			break;
		case '2':
			if (Mac_B.size_x() != Mac_B.size_y())
			{
				std::cout << "Aby obliczyc wyznacznik, podaj macierz kwadratowa" << std::endl;
			}
			else
			{
				system("cls");
				printf("det(B) = %3.2f\n", Mac_B.wyznacznik(Mac_B.size_x(), Mac_B.stereo()));
			}
			break;
		}
		ENTER_continue();
		break;
	}
	case '7':	//Transponowanie macierzy
	{
		Macierz wynik;
		system("cls");
		std::cout << "Wybierz macierz do transponowania:" << std::endl;
		std::cout << "1.Macierz A" << std::endl;
		std::cout << "2.Macierz B" << std::endl;
		switch (_getch())
		{
		case '1':
		{
			system("cls");
			wynik.size_set(Mac_A.size_x(), Mac_A.size_y());
			wynik = Mac_A.transponowanie();
			wynik.show();
			wpis(wynik);
			break;
		}
		case '2':
		{
			system("cls");
			wynik.size_set(Mac_B.size_x(), Mac_B.size_y());
			wynik = Mac_B.transponowanie();
			wynik.show();
			wpis(wynik);
			break;
		}
		}
		ENTER_continue();
		break;
	}
	}
}

std::vector <std::string> Menu::wprowadzenie()
{
	int x = 1;
	int y = 1;
	bool cierpienie = true;
	bool katusze = true;
	std::vector <std::string> tablica;
	std::string liczba;

	system("cls");
	std::cout << "Aby zmienic wielkosc macierzy, uzyj strzalek\n";
	std::cout << "ENTER, aby zatwierdzic\n";
	while (katusze)
	{
		std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		std::cout << "Macierz: " << x << "x" << y;
		cierpienie = true;
		while (cierpienie)
		{
			switch (_getch())
			{
			case 72: //up arrow
			{
				y++;
				cierpienie = false;
				break;
			}
			case 80: //down arrow
			{
				if (y > 1)
				{
					y--;
				}
				cierpienie = false;
				break;
			}
			case 77: //right arrow
			{
				x++;
				cierpienie = false;
				break;
			}
			case 75: //left arrow
			{
				if (x > 1)
				{
					x--;
				}
				cierpienie = false;
				break;
			}
			case 13:
				cierpienie = false;
				katusze = false;
				break;
			}
		}
		std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		std::cout << "                   ";
	}

	system("cls");
	std::cout << "Wprowadz wartosci do macierzy:\n";
	std::cout << "Aby przejsc do natepnej komorki przycisnij ENTER\n";
	
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			std::cout << i << 'x' << j << ": ";
			std::cin >> liczba;
			try
			{
				bool kropka = false;
				bool minus = false;
				for (char c : liczba)
				{
					if (c == '.' && !kropka)
						kropka = true;
					else if (c == '-' && !minus)
						minus = true;
					else if (!isdigit(c))
						throw std::out_of_range("To nie jest liczba");
				}
				tablica.push_back(liczba);
			}
			catch (std::exception & e)
			{
				std::cout << "Podawaj tylko liczby, " << e.what() << std::endl;
				j--;
			}
		}
	}
	tablica.push_back(std::to_string(x));
	tablica.push_back(std::to_string(y));
	return tablica;
}

template <typename T>
std::vector <T> Menu::stworz(std::vector <std::string> wektor)
{
	int x = stoi(wektor.back());	//liczba kolumn.
	wektor.pop_back();
	int y = stoi(wektor.back());	//liczba wierszy.
	wektor.pop_back();
	bool typdouble = false;	//false - typ int, true - typ double.
	std::vector <T> wynik;

	typdouble = typ(wektor);
	if (typdouble == true)
	{
		for (int i = 0; i < wektor.size(); i++)
		{
			wynik.push_back(stod(wektor[i]));
		}
		wynik.push_back(x);
		wynik.push_back(y);
		return wynik;
	}
	if (typdouble == false)
	{
		for (int i = 0; i < wektor.size(); i++)
		{
			wynik.push_back(stoi(wektor[i]));
		}
		wynik.push_back(x);
		wynik.push_back(y);
		return wynik;
	}
}

bool Menu::typ(std::vector <std::string> A)
{
	bool typdouble = false;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].find('.') != A[i].npos)
		{
			typdouble = true;
			break;
		}
	}
	return typdouble;
}

void Menu::ENTER_continue()
{
	std::cout << "Kliknij ENTER, aby kontynuowac";
	while (_getch() != 13)
	{
		continue;
	}
}

void Menu::wpis(Macierz wynik)
{
	std::cout << "\nCzy chcesz wpisac macierz wynikowa do macierzy A lub B:" << std::endl;
	std::cout << "1.Wpisz do A" << std::endl;
	std::cout << "2.Wpisz do B" << std::endl;
	std::cout << "0.Nie wpisuj" << std::endl;
	switch (_getch())
	{
	case '1':
		Mac_A.usun();
		Mac_A = wynik;
		break;
	case '2':
		Mac_B.usun();
		Mac_B = wynik;
		break;
	}
}

