#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//  10 D 

int main()
{
    setlocale(0, "");
    srand(time(0));
    
    string mas_symbols = "A b r dfgg cvbb Cplusplus Csharp";
    ofstream out("symbols.txt", ios::out);

    out << mas_symbols;

    out.close();

    ifstream in("symbols.txt", ios::in);
    string buf[7]  ;
    int c = 0;
    while (!in.eof()) {
        in >> buf[c];
        c++;
    }
    
    //getline(in, buffer);
    in.close();

    cout << "String reading from .txt file <<symbols.txt>>: " <<
        "\"";  
    for (int i = 0; i < c; i++)
            cout<< buf[i]<< " ";
    cout << "\"" << endl;

    int max_length = 0,
        index = 0,
        count_words=0;
    cout << "\na)Самое длинное слово в файле: ";
    string t;
    vector<string> vector_words;
    for (size_t i = 0; i < c ; i++)
    {
        if (buf[i].length() > max_length) {
            t = buf[i];
            max_length = buf[i].length();
            index = i;
        }
        if (buf[i].length() > 1) {
            count_words++;
            vector_words.push_back(buf[i]);
        }
    }
    cout << "\"" << t << "\"\nКоличесвто символов в нем составляет: "<<
        t.size()<< endl;
    cout << "\nb)Всего слов в файле " << vector_words.size() << endl
        << "Все слова в файле: ";
    for (size_t i = 0; i < vector_words.size(); i++)
    {
        cout <<endl <<"Word №"<<i+1 <<"\t" << vector_words[i] << " ";
    }

     out.open("Newsymbols.txt", ios::out);

    for (size_t i = 0; i < vector_words.size(); i++)
    {
        out << vector_words[i];
    }

    cout << "\nВ файл <Newsymbols.txt> записаны все слова без пропусков и слов состоящих с одного смивола\n";
    out.close();
    cout << endl;
    system("pause");
    return 0;
}