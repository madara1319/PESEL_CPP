#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::pair;


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
	vector<int> temp{};
	temp=a;
	multiplyingDigits(temp,0,1);
	multiplyingDigits(temp,1,3);
	multiplyingDigits(temp,2,7);
	multiplyingDigits(temp,3,9);
	multiplyingDigits(temp,4,1);
	multiplyingDigits(temp,5,3);
	multiplyingDigits(temp,6,7);
	multiplyingDigits(temp,7,9);
	multiplyingDigits(temp,8,1);
	multiplyingDigits(temp,9,3);
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

void GenderCheck(vector<int>& a)
{
	int GenderControlNumber{a.at(6)*1000+a.at(7)*100+a.at(8)*10+a.at(9)};
	if (GenderControlNumber % 2 !=0 )
		cout<<"Male"<<endl;
	else
		cout<<"Female"<<endl;
}


int CheckSum(int& temp)
{
	temp=temp % 10;
	temp=10 - temp;
	temp=temp % 10;
	return temp;
}

void EqualComparer(int& temp1, int& temp2)
{
	if (temp1==temp2)
		cout<<"That is a correct PESEL number"<<endl;
	else
		cout<<"That is an incorrect PESEL number"<<endl;
}

pair<int,int> BirthDate(vector<int>& a)
{
	int Year{a.at(0)*10+a.at(1)};
	int Month{a.at(2)*10+a.at(3)};
	if (Month>=0 & Month<=12)
	{
		Month=Month;
		Year=Year+1900;
	}
	else if(Month>=20 & Month<=32)
	{
		Month=Month-20;
		Year=Year+2000;
	}
	else if(Month>=40 & Month<=52)
	{
		Month=Month-40;
		Year=Year+2100;
	}
	else if(Month>=60 & Month<=72)
	{
		Month=Month-60;
		Year=Year+2200;
	}
	else if(Month>=80 & Month<=92)
	{
		Month=Month-80;
		Year=Year+1800;
	}
	return {Year,Month};

}

void BirthYear(vector<int>& a)
{
	cout<<"Rok urodzenia"<<a.at(0)*10+a.at(1)<<endl;
	cout<<"Data narodzin to "<<BirthDate(a).first<<" "<<BirthDate(a).second<<" "<<a.at(4)*10+a.at(5)<<endl;

}

vector<int> ConstPesel{};

void DisplayPesel(vector<int>& a)
{
	for (int i{}; i < a.size(); i++)
	{
		cout << a.at(i) << " ";
	}
	cout<<"\n";
}

vector<int> VectorToVector(vector<int>& a)
{
	for (auto& i : a)
		ConstPesel.push_back(i);
	return ConstPesel;	
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
//	pesel.assign({ 0,2,0,7,0,8,0,3,6,2,8 });

	int peselLength{ 10 };
	cout << "Enter yout pesel number" << endl;
	unsigned int temp{};
	temp=getNumber();
	if (temp>99999999999 | temp<10000000000)
		cout<<"Incorrect pesel number"<<endl;
	else

//	for (int j{}; j <= peselLength; j++)
//	{
//		unsigned int temp{};
//		temp = getNumber();
//		while (!(temp <= 9) && (temp >= 1))
//		{
//			cout << "error" << endl;
//			temp = getNumber();
//		}
//		pesel.push_back(temp);
//	}
VectorToVector(pesel);
DisplayPesel(ConstPesel);
DisplayPesel(pesel);
checker(pesel);
int ControlNumber{SumVector(pesel)};
int number=CheckSum(ControlNumber);
EqualComparer(number, ConstPesel.back());
BirthYear(ConstPesel);	
DisplayPesel(pesel);
DisplayPesel(ConstPesel);
GenderCheck(ConstPesel);

}

