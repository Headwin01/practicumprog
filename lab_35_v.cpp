#include <iostream> 
#include <map> 
#include <algorithm>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;


int* generate_mas(int count) {

    int* m = new int[count];

    cout << "\nСгенерирована последовательность заданого рекурентного соотношения: \n";
    for (size_t i = 0; i < count; i++)
    {
        if (i < 1) {
            m[i] = rand() % 10;
        }
        if (i >= 1 && i <= 3) {
            m[i] = m[i - 1] + 0 + 100;
        }
        if (i > 3) {
            m[i] = m[i - 1] + m[i - 3] + 100;
        }
        cout << m[i] << " ";
    }
    return m;
}
int main()
{
    setlocale(0, "");
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int c = 3 + rand() % 10;
    int* m = generate_mas(c);

    cout << "\nMin elem: " << m[0] << endl;
    cout << endl;
    system("pause");
    return 0;
}