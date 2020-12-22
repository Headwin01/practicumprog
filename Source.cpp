#include <iostream>
using namespace std;
//клас дріб
class Fraction
{
public:
	//методи для встановлення значень змінних (знаменника та чисельника)
	void setDenom(int denom);
	void setNum(int num);
	//конструктор
	Fraction(int  num = 0, int denom = 1);
	//метод для виводу дробу на екран
	void print() const;
	
private:
	//поля чисельника та знаменника відповідно
	int _num = 0, _denom = 1;
};
//клас власного виключення
class WrongFractionNumDataException
{
public:
	WrongFractionNumDataException(const string& message = "Denominator cannot be 0!")
		: message(message)
	{}
	//метод, щоб отримати повідомлення, що пішло не так
	const string& what() const
	{
		return message;
	}
private:
	//поле для збереження повідомлення про помилку
	string message;
};

void Fraction::setDenom(int denom)
{
	if (denom == 0)
	{
		//якщо знаменник = 0 то генеруємо виключну ситуацію
		throw WrongFractionNumDataException();
	}
	else
	{
		//в іншому випадку встановлюємо значення
		_denom = denom; 
		if (_denom < 0) 
		{
			_denom = -_denom;
			_num = -_num;
		}
	}
}

void Fraction::setNum(int num)
{
	this->_num = num;
}

Fraction::Fraction(int num, int denom)
{
	setNum(num);
	setDenom(denom);
}

void Fraction::print() const
{
	cout << _num << " / " << _denom << endl;
}


int main()
{
	//створюємо дріб
	Fraction f(5, 2);
	//виводимо його на екран
	f.print();
	//обгортаємо блоками try/catch можливе виключення, яке може статись
	try
	{
		f.setDenom(0);
	}
	catch (const WrongFractionNumDataException& ex)
	{
		//показуємо повідомлення про помилку
		cout << ex.what();
	}


	return 0;
}