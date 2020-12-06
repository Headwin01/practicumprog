#include <iostream> 
#include <map> 
#include <algorithm>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;

// 46 G (-1)^k * x^2k+1 / k! * (2k+1)!

// Driver program 

long double fact(int N) {

    if (N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return N * fact(N - 1); // делаем рекурсию.
}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float Sum = 0.0,
          k = 0,
          x=10+rand()%10;

    for (size_t i = 0; i < x; i++)
    {
        Sum += (float)pow((-1), k) * pow(x, (2 * k + 1)) / fact(k) * fact((2 * k + 1));
    }
    cout << "\nEndless sum(x)="<<x<<" = " << Sum << endl;

    system("pause");
    return 0;
}