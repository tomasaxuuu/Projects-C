// 10 laba.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "10 laba.h"
#include <stdio.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int arr[15][15]{};
int n, m;
int px, py;
int key;
// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY10LABA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY10LABA));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY10LABA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY10LABA);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
 
       FILE* f1;
       fopen_s(&f1, "E:\\10 laba(lvl 1).txt", "rt");
       fscanf_s(f1, "%d%d%d%d", &n, &m, &px, &py);
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               fscanf_s(f1, "%d", &arr[i][j]);
           }
       }
       fclose(f1);
   
   
   
  
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_KEYDOWN:
        key = wParam;
        if (key == VK_LEFT) {
            if (arr[py][px - 1] == 0) {
                px--;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py][px - 1] == 4) {
                px--;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py][px - 1] == 2 || arr[py][px - 1] == 3 || arr[py][px - 1] == 5) {
                px--;
                InvalidateRect(hWnd, NULL, TRUE);
                MessageBoxA(hWnd, "goodjob", "nice one, bro", MB_OK);
            }
        }
        else if (key == VK_RIGHT) {
            if (arr[py][px + 1] == 0) {
                px++;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py][px + 1] == 4) {
                px++;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py][px + 1] == 2 || arr[py][px + 1] == 3 || arr[py][px + 1] == 5) {
                px++;
                InvalidateRect(hWnd, NULL, TRUE);
                MessageBoxA(hWnd, "goodjob", "nice one, bro", MB_OK);
            }      
        }
        else if (key == VK_DOWN) {
            if (arr[py + 1][px] == 0) {
                py++;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py + 1][px] == 4) {
                py++;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py + 1][px] == 2 || arr[py + 1][px] == 3 || arr[py + 1][px] == 5) {
                py++;
                InvalidateRect(hWnd, NULL, TRUE);
                MessageBoxA(hWnd, "goodjob", "nice one, bro", MB_OK);
            }
        }
        else if (key == VK_UP) {
            if (arr[py - 1][px] == 0) {
                py--;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py - 1][px] == 4) {
                py--;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else if (arr[py - 1][px] == 2 || arr[py - 1][px] == 3 || arr[py - 1][px] == 5) {
                py--;
                InvalidateRect(hWnd, NULL, TRUE);     
                MessageBoxA(hWnd, "goodjob", "nice one, bro", MB_OK);
            }
        }
        if (arr[py][px] == 4) {
            FILE* f1;
            fopen_s(&f1, "E:\\10 laba(lvl 1).txt", "rt");
            fscanf_s(f1, "%d%d%d%d", &n, &m, &px, &py);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    fscanf_s(f1, "%d", &arr[i][j]);
                }
            }
            fclose(f1);
            MessageBoxA(hWnd, "Sorry", "Level losed -_-", MB_OK);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (arr[py][px] == 2) {
            FILE* f2;
            fopen_s(&f2, "E:\\10 laba(lvl 2).txt", "rt");
            fscanf_s(f2, "%d%d%d%d", &n, &m, &px, &py);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    fscanf_s(f2, "%d", &arr[i][j]);
                }
            }
            fclose(f2);
            MessageBoxA(hWnd, "Go next level ->", "Level completed :)", MB_OK);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (arr[py][px] == 3) {
            FILE* f2;
            fopen_s(&f2, "E:\\10 laba(lvl 3).txt", "rt");
            fscanf_s(f2, "%d%d%d%d", &n, &m, &px, &py);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    fscanf_s(f2, "%d", &arr[i][j]);
                }
            }
            fclose(f2);
            MessageBoxA(hWnd, "Go next level ->", "Level completed :)", MB_OK);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (arr[py][px] == 5) {
            MessageBoxA(hWnd, "Cool!", "Congratulations :)", MB_OK);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        InvalidateRect(hWnd, NULL, TRUE);

        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        ShowWindow(hWnd, SW_MAXIMIZE);
        HBRUSH Field, Wall, Player, Finish, Monster;
        Field = CreateSolidBrush(RGB(221, 160, 221));
        Wall = CreateSolidBrush(RGB(70, 70, 70));
        Finish = CreateSolidBrush(RGB(255, 0, 0));
        Player = CreateSolidBrush(RGB(154, 205, 50));
        Monster = CreateSolidBrush(RGB(0, 0, 128));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    SelectObject(hdc, Field);
                }
                else if (arr[i][j] == 1) {
                    SelectObject(hdc, Wall);
                }
                else if (arr[i][j] == 2 || arr[i][j] == 3 || arr[i][j] == 5) {
                    SelectObject(hdc, Finish);
                }
                else {
                    SelectObject(hdc, Monster);
                }
                Rectangle(hdc, 50 + j * 40, 50 + i * 40, 90 + j * 40, 90 + i * 40);
            }
        }

        SelectObject(hdc, Player);
        Rectangle(hdc, 55 + px * 40, 55 + py * 40, 85 + px * 40, 85 + py * 40);

        DeleteObject(Player);
        DeleteObject(Finish);
        DeleteObject(Wall);
        DeleteObject(Field);
        DeleteObject(Monster);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
