#include <iostream>
#include <vector>
using namespace std;
void print_operand(vector<int> vector);
int ConvertToDecimal(vector<int> vector);

void main()
{
	setlocale(0, "ru");
	vector<int> binary_operand({ 1,0,0,0,1,0,1,0,1,0,0,0 });
	print_operand(binary_operand);
	cout << ConvertToDecimal(binary_operand);
	int n = 0;
	cout << "\nВведите число количество скольких младшых бит не заменять на 1 (n > 0 && n < 12)  ";
	cin >> n;
	for (size_t i = n; i < binary_operand.size(); i++)
	{
		binary_operand[i] = 1;
	}
	cout << "\nБинарный операнд после изменений " << endl;
	print_operand(binary_operand);
	cout << ConvertToDecimal(binary_operand);
}

void print_operand(vector<int> vector) // digit capacity - разрядность исходного числа
{
	cout << "Наше исходное 12-разрядное двоичное число: ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		cout << vector[i];
	}
}

int ConvertToDecimal(vector<int> vector)
{
	cout << "\nРезультат конвертирования в систему счисления по основанию 10: ";
	int decimal_digit = 0;
	for (size_t i = 0; i < vector.size(); i++)
	{
		decimal_digit += vector[i] * pow(2, vector.size() - 1 - i);
	}
	return decimal_digit;
}
