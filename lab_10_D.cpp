#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

//  10 D 
int* fill_array( int c) {

    int* a = new int[c];
    for (size_t i = 0; i < c; i++)
    {
        a[i] = rand() % 100;
    }
    return a;
}

void show(int* a, int c) {

    for (size_t i = 0; i < c; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(0, "");
    srand(time(0));
    
    int count = 10,
       * mas_digits = fill_array(count);
    int count_paired_indexes = 0,
        count_unpaired_indexes = 0,
        min=100000, max=-100000;
    // min paired/ max unpaired
    for (size_t i = 0; i < count; i++)
    {
        if ((i + 1) % 2 == 0) {
            if (mas_digits[i] < min) {
                min = mas_digits[i];
            }
            count_paired_indexes++;
        }
        if ((i + 1) % 2 != 0) {
            if (mas_digits[i] > max) {
                max = mas_digits[i];
            }
            count_unpaired_indexes++;
        }
    }
    show(mas_digits, count);
    cout << "\nКоличество элементов на парных позицыях "
         << count_paired_indexes <<
         "\nКоличество на непраных позициях: " <<
         count_unpaired_indexes << endl;
    cout << "\nMax element in unpaired position: " 
         << max << "\nMin elem in paired pos: " << min<< endl;
    cout << "Sum min+max = " << min + max;
     system("pause");

    return 0;
}