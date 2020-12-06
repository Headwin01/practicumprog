#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <ctime>
using namespace std;




int** ganerate_matrix(int row, int col) {
	int** matrix = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		matrix[i] = new int[col] {};
	}
	return matrix;
}

void fill_matrix_any_digits(int** m, int row, int col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t q = 0; q < col; q++)
		{
			m[i][q] = rand() % 100;
		}
	}
}

void display_matrix(int** m, int row ,int col) {

	for (size_t i = 0; i < row; i++)
	{
		for (size_t q = 0; q < col; q++)
		{
			cout << m[i][q] << "\t";
		}
		cout << endl;
	}
}

int** push_back_new_col(int** m, int row, int& col)
{
	int* new_col = new int[row];
	cout << "\nСгенерированые значения для нового столбца матрицы\n";
	for (size_t i = 0; i < row; i++)
	{
		cout << (new_col[i] = rand() % 100) << " ";
	}
	int new_column = col + 1;
	int** new_matrix = new int*[row];
	cout << endl;
	for (size_t i = 0; i < row; i++)
	{
		new_matrix[i] = new int[new_column];
	}
	col = new_column;
	int c = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t q = 0; q < new_column; q++)
		{
			if (q == new_column - 1) {
				new_matrix[i][q] = new_col[c];
				c++;
			}
			else {
				new_matrix[i][q] = m[i][q];

			}
		}
	}
	return new_matrix;
}
int main() {
	setlocale(0, "");
	srand(time(NULL));
	int row = 2+rand()%5,
		col = 2+rand() %5;

	int** m = ganerate_matrix(row, col);
	fill_matrix_any_digits(m, row, col);

	cout << "\nСгенерированая матрица порядка " << row << "x" << col << endl;
	display_matrix(m, row, col);

	m = push_back_new_col(m, row, col);

	cout << "\nНовая матрица получена путем добавления к предыдущей нового столбца: \n";
	cout << endl << row << " " << col << endl;
	display_matrix(m, row, col);

	return 0;
}