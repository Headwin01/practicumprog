#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {

    srand(time(0));
    setlocale(0, "");
    
    float Sum = 0.0, a = rand() % 10, b = rand() %10;
    int count_digit = 10 + rand() % 10, index = 1;
    cout << "\nПросумировать ряд чисел: \n";

    float* mas_digit_a = new float[count_digit],
         * mas_digit_b = new float[count_digit];

    for (size_t i = 0; i < count_digit; i++)
    {
        mas_digit_a[i] = 22.3 - rand() % 100 + 33.1;
        mas_digit_b[i] = 12.3 - rand() % 10 + 33.1;
    }
    for (size_t k = 0; k < count_digit; k++)
    {
        Sum += pow(2, k + 1) / (mas_digit_a[k] + mas_digit_b[k]);
    }
    cout << "\nSum -> " << Sum;
    // 2^k / Ak + BK 

    return 0;
}