#include <iostream>
#include <string>
using namespace std;

string delPos(string str); // функция для удаления всех проверочных битов при выводе финального сообщения

int main() {
	setlocale(LC_ALL, "Rus");
	string mes, code; // строки для записи исходного сообщения и кодированного сообщения
	string b1, b2, b3, b4, b5, b; // проверочные биты(их всего 5, так как 31-26 = 5
	string s1, s2, s3, s4, s5, s; // синдромы
	string final; // ошибочный бит при декодировании
	int error, bit = 0, enter, sum = 0, colvo = 0;
		cout << "КОДИРОВАНИЕ:" << endl << endl;
		cout << "Введите сообщение из 26 битов:\n";
		cin >> mes;
		while (true) {
			if (mes.size() != 26) {
				cout << "Сообщение должно содержать 26 битов!" << endl;
				cin >> mes;
			}
			else {
				break;
			}
		}
		cout << endl;
		code = mes;
		code.insert(0, 1, 'x');
		code.insert(1, 1, 'x');
		code.insert(3, 1, 'x');
		code.insert(7, 1, 'x');
		code.insert(15, 1, 'x'); // замена всех степеней 2, до 2^4 на x
		cout << "Исходное сообщение:\n" << mes << endl << endl;
		cout << "Обозначим 'x' контрольные биты:\n" << code << endl << endl;
		b1 = to_string((code[2] + code[4] + code[6] + code[8] + code[10] + code[12] + code[14] + code[16] + code[18] + code[20] + code[22] + code[24] + code[26] + code[28] + code[30]) % 2);
		b2 = to_string((code[2] + code[5] + code[6] + code[9] + code[10] + code[13] + code[14] + code[17] + code[18] + code[21] + code[22] + code[25] + code[26]) % 2);
		b3 = to_string((code[4] + code[5] + code[6] + code[11] + code[12] + code[13] + code[14] + code[19] + code[20] + code[21] + code[22] + code[27] + code[28] + code[29] + code[30]) % 2);
		b4 = to_string((code[8] + code[9] + code[10] + code[11] + code[12] + code[13] + code[14] + code[23] + code[24] + code[25] + code[26] + code[27] + code[28] + code[29] + code[30]) % 2);
		b5 = to_string((code[16] + code[17] + code[18] + code[19] + code[20] + code[21] + code[22] + code[23] + code[24] + code[25] + code[26] + code[27] + code[28] + code[29] + code[30]) % 2);
		// поиск проверочных битов
		cout << "Вычисляем контрольные биты:\n";
		cout << b1 << ' ' << b2 << ' ' << b3 << ' ' << b4 << ' ' << b5 << endl << endl;
		b = b1 + b2 + b3 + b4 + b5; // строка проверочных битов
		int j = 0;
		for (int i = 0; i < code.size() - 1; i++) {
			if (code[i] == 'x') {
				code[i] = b[j];
				j++;
			}
		} // вставка проверочных битов вместо 'x'
		cout << "Получившееся сообщение:\n" << code << endl << endl;
		cout << "ДЕКОДИРОВАНИЕ:" << endl << endl;
		cout << "Ввести ошибку?:\n1. Да\n2. Нет" << endl;
		cin >> enter;
		switch (enter) {
		case 1:
			cin >> error;
			if (code[error - 1] == '0') {
				code[error - 1] = '1';
			}
			else {
				code[error - 1] = '0';
			}
			cout << "Сообщение с ошибкой:\n" << code << endl << endl;
			for (int i = 0; i < code.size() - 1; i++) {
				s1 = to_string((b[0] + code[2] + code[4] + code[6] + code[8] + code[10] + code[12] + code[14] + code[16] + code[18] + code[20] + code[22] + code[24] + code[26] + code[28] + code[30]) % 2);
				s2 = to_string((b[1] + code[2] + code[5] + code[6] + code[9] + code[10] + code[13] + code[14] + code[17] + code[18] + code[21] + code[22] + code[25] + code[26]) % 2);
				s3 = to_string((b[2] + code[4] + code[5] + code[6] + code[11] + code[12] + code[13] + code[14] + code[19] + code[20] + code[21] + code[22] + code[27] + code[28] + code[29] + code[30]) % 2);
				s4 = to_string((b[3] + code[8] + code[9] + code[10] + code[11] + code[12] + code[13] + code[14] + code[23] + code[24] + code[25] + code[26] + code[27] + code[28] + code[29] + code[30]) % 2);
				s5 = to_string((b[4] + code[16] + code[17] + code[18] + code[19] + code[20] + code[21] + code[22] + code[23] + code[24] + code[25] + code[26] + code[27] + code[28] + code[29] + code[30]) % 2);
			}
			s = s1 + s2 + s3 + s4 + s5;
			cout << "Синдром:\n";
			for (int i = s.size() - 1; i >= 0; i--) {
				cout << s[i] << ' ';
				final += s[i];
			}
			cout << endl << endl;
			for (int i = final.size() - 1; i >= 0 ; i--) {
				if (final[i] == '1') {
					sum += pow(2, colvo);
				}
				colvo++;
			}
			cout << "Ошибка в " << sum << " бите" << endl << endl;
			if (code[sum - 1] == '0') {
				code[sum - 1] = '1';
			}
			else {
				code[sum - 1] = '0';
			}
			if (mes == delPos(code)) {
				cout << "Сообщение c исправленным " << sum << " битом:\n" << delPos(code) << endl << endl;
			}
			break;
		case 2:
			for (int i = 0; i < code.size() - 1; i++) {
				s1 = to_string((b[0] + code[2] + code[4] + code[6] + code[8] + code[10] + code[12] + code[14] + code[16] + code[18] + code[20] + code[22] + code[24] + code[26] + code[28] + code[30]) % 2);
				s2 = to_string((b[1] + code[2] + code[5] + code[6] + code[9] + code[10] + code[13] + code[14] + code[17] + code[18] + code[21] + code[22] + code[25] + code[26]) % 2);
				s3 = to_string((b[2] + code[4] + code[5] + code[6] + code[11] + code[12] + code[13] + code[14] + code[19] + code[20] + code[21] + code[22] + code[27] + code[28] + code[29] + code[30]) % 2);
				s4 = to_string((b[3] + code[8] + code[9] + code[10] + code[11] + code[12] + code[13] + code[14] + code[23] + code[24] + code[25] + code[26] + code[27] + code[28] + code[29] + code[30]) % 2);
				s5 = to_string((b[4] + code[16] + code[17] + code[18] + code[19] + code[20] + code[21] + code[22] + code[23] + code[24] + code[25] + code[26] + code[27] + code[28] + code[29] + code[30]) % 2);
			}
			s = s1 + s2 + s3 + s4 + s5;
			cout << "Синдром:" << endl;
			for (int i = s.size() - 1; i >= 0; i--) {
				cout << s[i] << ' ';
			}
			cout << endl << endl;
			if (mes == delPos(code)) {
				cout << "Сообщение передано без ошибок:\n" << delPos(code) << endl << endl;
			}
			break;
		}
		cout << endl;
	return 0;
}

string delPos(string str) {
	str.erase(0, 2);
	str.erase(1, 1);
	str.erase(4, 1);
	str.erase(11, 1);
	return str;
}