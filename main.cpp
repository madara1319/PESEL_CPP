#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::cin;
using std::vector;


int lastDigit(int n)
{
	return (n % 10);
}

void multiplyingDigits(vector<int>& a, int vecIndex , int multiplier)
{
	a.at(vecIndex) = a.at(vecIndex) * multiplier;;
}

void multiplyingDigitsTest(vector<int>& a, int vecIndex , int multiplier)
{
	int multiplicationTest{};
	multiplicationTest = a.at(vecIndex) * multiplier;
	if (multiplicationTest > 9)
	{
		a.at(vecIndex)=lastDigit(multiplicationTest);
	}
	else
	{
		a.at(vecIndex) = multiplicationTest;
	}
}


void controlSum(vector<int>& a)
{
	int sum{};
	for (auto i : a)
	{

		cout << i << " ";
		sum = sum + i;
		cout << sum << endl;
	}
	cout << "\n Suma kontrolna = " << sum;
}



void checker(vector<int>& a)
{
//	int multiplicationTest{};
	vector<int> temp{};
	temp=a;
	multiplyingDigits(temp,0,1);
	cout << "1 cyfra numeru peselu razy 1 = " << temp.at(0) << endl;

	multiplyingDigits(temp,1,3);
	cout << "2 cyfra numeru peselu razy 3 = " << temp.at(1) << endl;

	multiplyingDigits(temp,2,7);
	cout << "3 cyfra numeru peselu razy 7 = " << temp.at(2) << endl;

	multiplyingDigits(temp,3,9);
	cout << "4 cyfra numeru peselu razy 9 = " << temp.at(3) << endl;

	multiplyingDigits(temp,4,1);
	cout << "5 cyfra numeru peselu razy 1 = " << temp.at(4) << endl;

	multiplyingDigits(temp,5,3);
	cout << "6 cyfra numeru peselu razy 3 = " << temp.at(5) << endl;

	multiplyingDigits(temp,6,7);
	cout << "7 cyfra numeru peselu razy 7 = " << temp.at(6) << endl;

	multiplyingDigits(temp,7,9);
	cout << "8 cyfra numeru peselu razy 9 = " << temp.at(7) << endl;

	multiplyingDigits(temp,8,1);
	cout << "9 cyfra numeru peselu razy 1 = " << temp.at(8) << endl;

	multiplyingDigits(temp,9,3);
	cout << "10 cyfra numeru peselu razy 3 = " << temp.at(9) << endl;
	a=temp;
}

int sum_of_elems{};

int SumVector(vector<int>& a)
{
	int n{};

	for (n = 0; n != a.size()-1; n++){
		sum_of_elems+=a.at(n);
	}
	return sum_of_elems;
}

int CheckSum(int& temp)
{
	cout<<"i check this numba = "<<temp<<endl;
	temp=temp % 10;
	cout<<"rest division by 10 = "<<temp<<endl;
	temp=10 - temp;
	cout<<"10 - my numba = "<<temp<<endl;
	temp=temp % 10;
	cout<<"rest division by 10 = "<<temp<<endl;
	return temp;
}

void EqualComparer(int& temp1, int& temp2)
{
	if (temp1==temp2)
		cout<<"good"<<endl;
	else
		cout<<"no good"<<endl;
}

//algorytmika
//klasa osoba
//obiekty do wywolywania klasy osoba
//generator pesel
//znam data urodzenia, plec
//generuje pesel na podstawie tego
//klasa do dodawania parametrow
//zrobic prymitywna baze danych(ew SQL)
//jakis plik primytuwna baza danych
//odczytywanie z niej i sprawdzanie
//program do dostanie sie do mysqla na agh przez poczte






int getNumber()
{
	int temp{};
	cin>>temp;
	return temp;
}

int main()
{
	vector<int> pesel;
	pesel.assign({ 0,2,0,7,0,8,0,3,6,2,8 });
	checker(pesel);
	int ControlNumber{SumVector(pesel)};

	int number=CheckSum(ControlNumber);
	EqualComparer(number, pesel.back());
		

//	int peselLength{ 10 };
//	cout << "Enter yout pesel number" << endl;
//	for (int j{}; j <= peselLength; j++)
//	{
//
//		unsigned int temp{};
//
//		temp = getNumber();
//		while (!(temp <= 9) && (temp >= 1))
//		{
//			cout << "error" << endl;
//			temp = getNumber();
//		}
//
//		pesel.push_back(temp);

//	}
//
//	checker(pesel);
//for (int i{}; i < pesel.size(); i++)
//{
//	cout << pesel.at(i) << " ";
//}
//
}
