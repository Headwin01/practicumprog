#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <ctime>
using namespace std;

struct Matrix {
	int row,
		col;
	int** matrix;
};

Matrix generate_matrix(Matrix* m) {

	m->row = 3+rand() % 3,
	m->col = 3 + rand() % 3;
	m->matrix = new int* [m->row];

	for (int i = 0; i < m->row; i++) {
		m->matrix[i] = new int[m->col]{};
	}

	for (size_t i = 0; i < m->row; i++)
	{
		for (size_t q = 0; q < m->col; q++)
		{
			m->matrix[i][q] = 1 + rand() % 5;
		}
	}

	return *m;
}

Matrix* ganerate_massive_matrices(int count_matrix) {
	
	Matrix* mas_matrices = new Matrix[count_matrix];

	//int** matrix = new int* [row];
	for (size_t i = 0; i < count_matrix; i++)
	{
		mas_matrices[i] = generate_matrix(&mas_matrices[i]);
	}
	return mas_matrices;
}

void fill_matrix_any_digits(int** m, int row, int col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t q = 0; q < col; q++)
		{
			m[i][q] = rand() % 2;
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

void show_massive_matrices(Matrix* m, int count) {

	for (size_t c = 0; c < count; c++)
	{
		cout << "\nMatrix " << m[c].row<< "x"<< m[c].col << " №" << c + 1 << endl;
		for (size_t i = 0; i < m[c].row; i++)
		{
			for (size_t q = 0; q < m[c].col; q++)
			{
				cout << m[c].matrix[i][q] << "\t";
			}
			cout << endl;
		}
	}
}

void clear_memory(Matrix * m, int count) {

	for (size_t i = 0; i < count; i++)
	{
		for (size_t q = 0; q < m[i].row; q++)
		{
			//int* t = m[i].matrix[i];

			delete[] m[i].matrix[q];
		}
	}
	delete[] m;
	m = nullptr;
}

long long* multiplay_elems_matrices(Matrix* m, int count) {

	long long* mas = new long long[count];
	for (size_t i = 0; i < count; i++)
	{
		mas[i] = 1;
	}

	int counter_mas = 0;
	for (size_t c = 0; c < count; c++)
	{
		mas[c] = 1;
		for (size_t i = 0; i < m[c].row; i++)
		{
			for (size_t q = 0; q < m[c].col; q++)
			{
				mas[c] *= m[c].matrix[i][q] ;
			}
		}
		cout << "\nПроизвидения єлементов матрицы №" << c + 1 << ": " << mas[c];
		
	}
	
	return mas;
}
int main(int argc, char* argv[]) {

	setlocale(0, "");
	srand(time(NULL));
	int row = 2+rand()%5,
		col = 2+rand() %5;
	int count_matrices = 10;
	Matrix* mas_matrices = ganerate_massive_matrices(count_matrices);	

	show_massive_matrices(mas_matrices, count_matrices);

	 long long* mas_multyplay_matrices =multiplay_elems_matrices(mas_matrices, count_matrices);

	//clear_memory(mas_matrices, count_matrices);
	return 0;
}