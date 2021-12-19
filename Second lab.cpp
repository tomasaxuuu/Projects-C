#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <cstring>
using namespace std;
// часть а
void four(char arr1[], char arr2[]); // умножение в 4 системе
// часть б
string cel_chast(int a); // перевод целой части в 2
string float_chast(double a); // перевод дробной части в 2
string sign_(int sym); // знак
string mantissa(string change); // нормализованный вид, мантисса
string exponent(string exp); // порядок aka экспонента
int main() {
	setlocale(LC_ALL, "Rus");
	// часть a)
	cout << "Part(a):" << endl << endl;
	char ch1[100];
	char ch2[100];
	four(ch1, ch2);
	cout << endl << endl;
	// часть b)
	cout << "Part(b):" << endl << endl;
	double chislo = -763.200345;
	string sign, normaliz, bin, expi, res, mantis_norm, final1;
	sign = sign_(chislo);
	bin = cel_chast((int)abs(chislo)) + "." + float_chast(stod(to_string(abs(chislo) - (int)abs(chislo))));
	normaliz = mantissa(bin);
	expi = exponent(bin);
	cout << "Number: -763, 200345" << endl;
	cout << "In the 2nd system : " << bin << endl;
	cout << "Sign of number: " << sign << endl;
	cout << "Exponent: " << expi << endl;
	cout << "Mantiss: " << normaliz << endl;
	cout << "Mantiss in normalized form: ";
	for (int i = 2; i <= 53; i++) {
		mantis_norm += normaliz[i];
	}
	cout << mantis_norm << endl;
	res = sign + expi + mantis_norm;
	cout << "Final_Result (sign + exponent + mantiss in normalized form):" << endl;
	cout << res << endl;
	system("pause");
	return 0;
}
// часть (а)
void four(char arr1[], char arr2[]) {
	cout << "Enter the first number: ";
	cin >> arr1;
	cout << "Enter the second number: ";
	cin >> arr2;
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	int result[100] = {};
	for (int i = 0; i < len1 + len2; i++) { // кол-во разрядов = кол-ву цифр в arr1 + arr2
		result[i] = 0;
	}
	for (int i = len2 - 1; i >= 0; --i) {
		for (int j = len1 - 1; j >= 0; --j) {
			result[i + j + 1] += (arr1[j] - '0') * (arr2[i] - '0'); // если не 0, то +; если 0, то -;
			if (result[i + j + 1] > 3) {
				result[i + j] += result[i + j + 1] / 4; // сложение с учетом переноса старших разрядов
				result[i + j + 1] %= 4;
			}
		}
	}
	cout << "The product of these numbers in the quaternary number system: ";
	for (int i = 0; i < len1 + len2; i++) {
		cout << result[i];
	}
	cout << endl;
}


// часть (б)
string cel_chast(int a) { // перевод целой части числа в 2 с.
	string number;
	while (a > 0) {
		number = to_string(a % 2) + number;
		a /= 2;
	}
	return number;
}
string float_chast(double a) { // перевод дробной части числа в 2 с.
	string number;
	while (a - (int)a > 0) {
		a *= 2;
		number += to_string((int)a);
		a -= (int)a;
	}
	return number;
}
string sign_(int sym) { // знак числа, или первый символ
	if (sym > 0) {
		return "0";
	}
	else {
		return "1";
	}
}
string mantissa(string change) { // сдвиг точки до первого знака(1)
	change.erase(change.find_first_of('.'), 1);
	change.erase(0, 1);
	change = "1." + change;
	return change;
}
string exponent(string exp) { // нахождение экспоненты, прибавление сдвига для точности double и перевод в 2 систему
	int ex = 0;
	for (int i = 1; i < exp.size(); i++) {
		if (exp[i] != '.') {
			ex++;
		}
		else {
			break;
		}
	}
	ex += (pow(2, 10) - 1); // смещение на 1023 для double точности
	return cel_chast(ex);
}
