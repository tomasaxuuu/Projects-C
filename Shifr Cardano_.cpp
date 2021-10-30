#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h> 
using namespace std;

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int SIZE = 4;
    string encoded[SIZE], shifr_str, deshifr_str, user_message, user_message_1;
    char shifr_matrix[SIZE][SIZE];
    int index = 0;
    int kard[SIZE][SIZE] = {{ 0, 0, 1, 0 },  //решетка Кардано; размеры решетки и сообщения равны
                            { 0, 0, 0, 1 },
                            { 0, 1, 0, 0 },
                            { 1, 0, 0, 0 }};
    cout << "Enter you message:" << endl;   // ввод сообщения
    getline(cin, user_message);
    cout << "\nUser_Matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (kard[i][j] == 1) {
                shifr_matrix[i][j] = user_message[index];  // начальное положение решетки:
                index++;
                cout << shifr_matrix[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
           if (kard[SIZE - j - 1][i] == 1) {
               shifr_matrix[i][j] = user_message[index];  // поворот решетки на 90 градусов
               index++;
               cout << shifr_matrix[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (kard[SIZE - i - 1][SIZE - j - 1] == 1) {
                shifr_matrix[i][j] = user_message[index];  // поворот решетки на 180 градусов
                index++;
                cout << shifr_matrix[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (kard[j][SIZE - i - 1] == 1) {
                shifr_matrix[i][j] = user_message[index];  // поворот решетки на 270 градусов
                index++;
                cout << shifr_matrix[i][j];
            }
        }
    }
    cout << "\n\nShifr matrix:" << endl;  // вывод получившейся строки
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            shifr_str += shifr_matrix[i][j];
            cout << shifr_matrix[i][j];
        }
        cout << endl;
    }
    cout << "\nShifr message:" << shifr_str << endl;  // строка с зашифрованным текстом
    int kard1[SIZE][SIZE] = {{ 0, 0, 1, 0 },
                            { 0, 0, 0, 1 },
                            { 0, 1, 0, 0 },
                            { 1, 0, 0, 0 }};
    cout << "\nEnter you shifr message:" << endl;  // ввод зашифрованного сообщения
    getline(cin, user_message_1);

    for (int i = 0; i < SIZE; i++){
        encoded[i] = user_message_1.substr(0, 4);
        user_message_1.erase(0, 4);
    }
    cout << "\nShifr_Matrix:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << encoded[i] << endl;
    }
    cout << "\nDeshifr matrix:" << endl;  // вывод зашифрованного сообщения
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (kard1[i][j] == 1) {
                deshifr_str += encoded[i][j];
                cout << encoded[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (kard1[SIZE - j - 1][i] == 1) {
                deshifr_str += encoded[i][j];
                cout << encoded[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (kard1[SIZE - i - 1][SIZE - j - 1] == 1) {
                deshifr_str += encoded[i][j];
                cout << encoded[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (kard1[j][SIZE - i - 1]== 1) {
                deshifr_str += encoded[i][j];
                cout << encoded[i][j];
            }
        }
    }
    cout << "\n\nDeshifr message: " << deshifr_str << endl;  // вывод получившейся строки
    getchar();
}