int isAfullSquer(int);
#include <iostream>
using namespace std;
int main() {
	setlocale(0, "rus");
	int n;
	cout << "Введите количество членов последовательности ряда целых чисел ";
	cin >> n;
	cout << endl;
	if (n <= 0) {
		cout << "Введено n = " << n << " а столько в ряду не бывает!" << endl;
		system("PAUSE");
		exit(1);
	}
	int* SeqAr = new int[n];
	int someInt = 0;
	for (int i = 0; i < n; i++) {
		cout << "Введите член an, ряда с номером " << i + 1 << " ";
		cin >> someInt;
		cout << endl;
		if (someInt < 0) {
			cout << "Введено an = " << someInt << " а это отрицательное число!" << endl;
			system("PAUSE");
			exit(1);
		}
		SeqAr[i] = someInt;
	}
	for (int i = 0; i < n; i++)
		cout << "Введен  an,  с номером " << i + 1 << " " << SeqAr[i] << endl;
	int NumberOfSqrts = 0;
	for (int i = 0; i < n; i++)NumberOfSqrts += isAfullSquer(SeqAr[i]);
	cout << "Всего найдено полных квадратов " << NumberOfSqrts << " штук(и)";
	cout << endl;
	system("PAUSE");
	return 0;
}
int isAfullSquer(int inInt) {
	double locDbl = (double)inInt;
	double root = sqrt(locDbl);
	if ((int)root * (int)root == inInt)return 1;
	return 0;
}