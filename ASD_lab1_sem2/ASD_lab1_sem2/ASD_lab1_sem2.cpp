
#include <iomanip>
#include <iostream>

using namespace std;

void matr_out(int*, int);
void fillRand(int*, int);
void fillTrue(int*, int);
void fillReverse(int*, int);
void bubbleSort(int*, int, unsigned int, unsigned int);
void shellSort(int* , int, unsigned int, unsigned int);
int newGap(int);

int main()
{
    int size, flag;
	unsigned int swapC = 0, compC = 0;

	cout << "Enter size of arrey:\n";
    cin >> size;

	int* mass = new int[size];

	cout << "How do you want to fill the array?\n 1 - random\n 2 - optimally\n 3 - revers\n";
	cin >> flag;
	switch (flag)
	{
	case 1:
		fillRand(mass, size);
		matr_out(mass, size);
		break;
	case 2:
		fillTrue(mass, size);
		matr_out(mass, size);
		break;
	case 3:
		fillReverse(mass, size);
		matr_out(mass, size);
		break;
	default:
		cout << "You enter invalid number!";
		return 0;
	}

	cout << "How do you want to sort the array?\n 1 - Bubble sort\n 2 - Shell sort\n";
	cin >> flag;
	switch (flag)
	{
	case 1:
		bubbleSort(mass, size, swapC, compC);
		break;
	case 2:
		shellSort(mass, size, swapC, compC);
		break;
	default:
		cout << "You enter invalid number!";
		return 0;
	}
}

void matr_out(int* mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}

void fillRand(int* mass, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % size;
	}
}

void fillTrue(int* mass, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		mass[i] = i+1;
	}
}

void fillReverse(int* mass, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		mass[i] = size - i;
	}
}

void bubbleSort(int* mass, int size, unsigned int swapC, unsigned int compC)
{
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			compC++;
			if (mass[j] > mass[j+1])
			{
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
				swapC++;
			}
		}
	}

	matr_out(mass, size);
	cout << "Count of swap = " << swapC << endl;
	cout << "Count of compare = " << compC << endl;
}

int newGap(int gap)
{
	gap /= 1.247;
	if (gap<1)
	{
		return 1;
	}
	return gap;
}

void shellSort(int* mass, int size, unsigned int swapC, unsigned int compC)
{
	int gap = size, temp;
	bool swap = true;

	while (gap >1 || swap == true)
	{
		swap = false;
		gap = newGap(gap);

		for (int i = 0; i < size - gap; i++)
		{
			compC++;
			if (mass[i] > mass[i+gap])
			{
				swapC++;
				temp = mass[i];
				mass[i] = mass[i + gap];
				mass[i + gap] = temp;
				swap = true;
			}
		}
	}

	matr_out(mass, size);
	cout << "Count of swap = " << swapC << endl;
	cout << "Count of compare = " << compC << endl;
}