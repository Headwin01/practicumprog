#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int m, n;
    cout << "Введите размер матрицы M: "; cin >> m;
    int** C = new int* [m], i, j;
    cout << "Исходная матрица равна: " << endl;
    for (i = 0; i < m; i++)
    {
        *(C + i) = new int[m];
        for (j = 0; j < m; j++)
        {
            *(*(C + i) + j) = rand() % 21;
            cout << *(*(C + i) + j) << "\t";
        }
        cout << endl;
    }
    int x;
   
   for(i=1; i < m; ++i)
   {
       for(j=0; j < i-1; ++j)
       {
           const int x=C[i][j];
           C[i][j]=C[j][i];
           C[j][i]=x;
       }
   }
   

    cout << endl;
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}