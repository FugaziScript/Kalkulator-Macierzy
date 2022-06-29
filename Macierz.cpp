#include "Macierz.h"
#include "Interface.h"

void Macierz::show()
{
	int licznik = 0;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (elementy[licznik] < 0)
				printf("[%d][%d]: %3.2f; ", i, j, elementy[licznik]);
			else
				printf("[%d][%d]:  %3.2f; ", i, j, elementy[licznik]);
			licznik++;
		}
		printf("\n");
	}
}

void Macierz::usun()
{
	elementy.clear();
	x = 0;
	y = 0;
}

void Macierz::size_set(int x, int y)
{
	this->x = x;
	this->y = y;
}

Macierz Macierz:: operator+(Macierz Mac)
{
	Macierz wynik;
	for (int i = 0; i < Mac.elementy.size(); i++)
	{
		wynik.elementy.push_back(this->elementy[i] + Mac.elementy[i]);
	}
	return wynik;
}

Macierz Macierz::operator-(Macierz Mac)
{
	Macierz wynik;
	for (int i = 0; i < Mac.elementy.size(); i++)
	{
		wynik.elementy.push_back(this->elementy[i] - Mac.elementy[i]);
	}
	return wynik;
}

Macierz Macierz::operator*(Macierz Mac)
{
	int licznik = 0;
	std::vector < std::vector<double>> A = this->stereo();
	std::vector < std::vector<double>> B = Mac.stereo();
	Macierz wynik;
	wynik.size_set(this->x, Mac.y);
	wynik.elementy.resize(this->x * Mac.y);

	for (int i = 0; i < this->x; i++)
	{
		for (int j = 0; j < Mac.y; j++)
		{
			wynik.elementy[licznik] = 0;
			for (int k = 0; k < Mac.x; k++)
			{
				wynik.elementy[licznik] = wynik.elementy[licznik] + A[i][k] * B[k][j];
			}
			licznik++;
		}
	}
	return wynik;
}

Macierz Macierz::operator*(double liczba)
{
	Macierz Mac;
	Mac.size_set(this->x, this->y);
	for (int i =0; i < this->elementy.size(); i++)
	{
		Mac.elementy.push_back(this->elementy[i] * liczba);
	}
	return Mac;
}

Macierz Macierz::transponowanie()
{
	std::vector < std::vector<double>> A = this->stereo();
	int licznik = 0;
	Macierz wynik;
	wynik.x = this->y;
	wynik.y = this->x;
	wynik.elementy.resize(x * y);
	for (int i = 0; i < this->y; i++)
	{
		for (int j = 0; j < this->x; j++)
		{
			wynik.elementy[licznik] = A[j][i];
			licznik++;
		}
	}
	return wynik;
}

Macierz Macierz::dopelnienie()
{
	Macierz wynik;
	std::vector < std::vector<double>> A;
	wynik.size_set(this->x, this->y);
	int licznik = 0;
	for (int i = 0; i < this->x; i++)
	{
		A.resize(this->x, std::vector<double>(this->y));
		A = this->stereo();
		for (int j = 0; j < this->y; j++)
		{
			A.erase(A.begin() + this->y);		//usuwanie wierszy
			for (int k = 0; k < A.size(); k++)	//usuwanie kolumn
			{
				A[i].erase(A[i].begin() + this->x);
			}
			A.resize(this->x-1, std::vector<double>(this->y -1));
			wynik.elementy[licznik] = znak_mac(i + j + 2) * wyznacznik(this->x-1, A);
			licznik++;
		}
	}
	return wynik;
}

double Macierz::wyznacznik(int rozmiar, std::vector<std::vector<double>> tablica_2d)
{
	std::vector <std::vector<double>> pomoc(rozmiar, std::vector<double>(rozmiar));
	double wyznacznik = 0;
	if (rozmiar == 1)
	{
		wyznacznik = tablica_2d[0][0];
	}	
	if (rozmiar > 1)
	{
		for (int i = 0; i < rozmiar; i++) //wiersze
		{
			for (int j = 1; j < rozmiar; j++) //wylanianie podmacierzy, kolumny +1, nowa macierz mniejsza o 1
			{
				for (int k = 0; k < rozmiar; k++)
				{
					if (i > k)
					{
						pomoc[k][j - 1] = tablica_2d[k][j];
					}
					if (i < k)
					{
						pomoc[k - 1][j - 1] = tablica_2d[k][j];
					}
				}
			}
			wyznacznik = wyznacznik + znak_mac(i) * tablica_2d[i][0] * Macierz::wyznacznik(rozmiar - 1, pomoc);
		}
	}
	return wyznacznik;
}

std::vector<std::vector<double>> Macierz::stereo()
{
	//zamiana tablicy jednowymiarowej na dwuwymiarowa
	std::vector < std::vector<double>> tablica_2d(x, std::vector<double>(y));
	int licznik = 0;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			tablica_2d[i][j] = elementy[licznik];
			licznik++;
		}
	}
	return tablica_2d;
}

int Macierz::znak_mac(int x)
{
	int wynik = 1;
	for (int i = 0; i < x; i++)
	{
		wynik = wynik * (-1);
	}
	return wynik;
}