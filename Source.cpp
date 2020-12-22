#include <iostream>
using namespace std;
//���� ���
class Fraction
{
public:
	//������ ��� ������������ ������� ������ (���������� �� ����������)
	void setDenom(int denom);
	void setNum(int num);
	//�����������
	Fraction(int  num = 0, int denom = 1);
	//����� ��� ������ ����� �� �����
	void print() const;
	
private:
	//���� ���������� �� ���������� ��������
	int _num = 0, _denom = 1;
};
//���� �������� ����������
class WrongFractionNumDataException
{
public:
	WrongFractionNumDataException(const string& message = "Denominator cannot be 0!")
		: message(message)
	{}
	//�����, ��� �������� �����������, �� ���� �� ���
	const string& what() const
	{
		return message;
	}
private:
	//���� ��� ���������� ����������� ��� �������
	string message;
};

void Fraction::setDenom(int denom)
{
	if (denom == 0)
	{
		//���� ��������� = 0 �� �������� �������� ��������
		throw WrongFractionNumDataException();
	}
	else
	{
		//� ������ ������� ������������ ��������
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
	//��������� ���
	Fraction f(5, 2);
	//�������� ���� �� �����
	f.print();
	//��������� ������� try/catch ������� ����������, ��� ���� �������
	try
	{
		f.setDenom(0);
	}
	catch (const WrongFractionNumDataException& ex)
	{
		//�������� ����������� ��� �������
		cout << ex.what();
	}


	return 0;
}