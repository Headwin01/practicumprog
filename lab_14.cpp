#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {

    srand(time(0));
    setlocale(0, "");
    float value = 0;
    vector<int> vec;
    do
    {
        cout << "\nВведите число, для завершения введите 0\t";
        cin >> value;
        if (value != 0)
             vec.push_back(value);

    } while (value != 0);
   
    cout << "\nВсе введенные вами числа до введения нуля \n";
    float sum = 0,
        multiplay = 1;
    for (size_t i = 0; i < vec.size(); i++)
    {
        sum += vec[i],
        multiplay *= vec[i];
        cout << vec[i] << " ";
    }

    double avrage_geom = (float)pow(multiplay, static_cast<double>(1. / (vec.size())));
    cout << "\nСреднее арифметическое введеных вами чесел: " << sum/vec.size();
    cout << "\nСреднее геометрическое введеных вами чесел: " << (double)avrage_geom;

    return 0;
}