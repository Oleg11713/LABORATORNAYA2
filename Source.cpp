#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>

using namespace std;

class Massiv
{
	int*** mas;
	int n;
	int a;
public:
	Massiv(int k, int l);
	void vvod();
	void display();
	int menu();
	void indZad();
	Massiv(const Massiv& arr)
	{
		a = arr.a;
		n = arr.n;
		mas = new int** [a];
		for (int k = 0; k < a; k++)
		{
			mas[k] = new int* [n];
			for (int i = 0; i < n; i++)
			{
				mas[k][i] = new int[n];
				for (int j = 0; j < n; j++)
					mas[k][i][j] = arr.mas[k][i][j];
			}
		}
	}	
	~Massiv();
};

Massiv::Massiv(int k, int l)
{
	n = k;
	a = l;
	mas = new int** [a];
	for (int k = 0; k < a; k++)
	{
		mas[k] = new int* [n];
		for (int i = 0; i < n; i++)
			mas[k][i] = new int[n];
	}
}

Massiv::~Massiv()
{
	for (int k = 0; k < a; k++)
	{
		for (int i = 0; i < n; i++)
			delete[] mas[k][i];
		delete[] mas[k];
	}
	delete[] mas;
}


void Massiv::vvod()
{
	int choice = menu();
	if (choice == 0)
	{
		int to, from;
		cout << "Enter boundaries" << endl;
		cout << "From: ";
		cin >> from;
		cout << "To: ";
		cin >> to;
		for (int k = 0; k < a; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					mas[k][i][j] = from + rand() % (to - from + 1);
	}
	else if (choice == 1)
	{
		cout << "Enter array elements: " << endl;
		for (int k = 0; k < a; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					cin >> mas[k][i][j];
	}
}

int Massiv::menu()
{
	int viborKnopki = 0, knopka;
	system("cls");
	while (true)
	{
		cout << "Choose a way to fill the array" << endl;
		viborKnopki = (viborKnopki + 2) % 2;

		if (viborKnopki == 0) cout << "-> Filling an array with random elements" << endl;
		else cout << "Filling an array with random elements" << endl;

		if (viborKnopki == 1) cout << "-> Filling an array from the keyboard" << endl;
		else cout << "Filling an array from the keyboard" << endl;

		knopka = _getch();
		if (knopka == 224)
		{
			knopka = _getch();
			if (knopka == 72) viborKnopki--;
			if (knopka == 80) viborKnopki++;
		}
		if (knopka == 13) { system("cls"); return viborKnopki; }
		system("cls");
	}
}

void Massiv::display()
{
	for (int k = 0; k < a; k++)
	{
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << endl;
			for (int j = 0; j < n; j++)
				cout << mas[k][i][j] << " ";
		}
	}
	cout << endl;
}

void Massiv::indZad()
{
	int mas1[1000];
	int mas2[1000];
	int count = 0;

	cout << "\nIntersection of array elements: ";
	for (int k = 0; k < a - 1; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
					for (int i1 = 0; i1 < n; i1++)
						for (int j1 = 0; j1 < n; j1++)
							if (mas[k][i][j] == mas[k + 1][i1][j1])
								if (mas1[mas[k][i][j]] != 1)
								{
									mas1[mas[k][i][j]] = 1;
									cout << mas[k][i][j] << " ";
									count++;
								}
	if (count == 0)
		cout << "No intersections";
	
	cout << endl << "\nConcatenation of array elements: ";

	for (int k = 0; k < a; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mas2[mas[k][i][j]] != 1) {
					mas2[mas[k][i][j]] = 1;
					cout << mas[k][i][j] << " ";
				}

	cout << endl;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int a = 2;
	int n;
	cout << "Enter the size of the arrays: ";
	cin >> n;
	Massiv arr(n, a);
	arr.vvod();
	cout << "Source arrays";
	arr.display();
	cout << "\nIndividual task:" << endl;
	arr.indZad();
}





