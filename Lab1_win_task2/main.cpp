#include<Windows.h>
#include<processthreadsapi.h>
#include<stdio.h>
/*
Этот код создает два потока, каждый из которых выполняет свою функцию:
вывод случайного числа с интервалом и вывод перевернутой строки ввода пользователя.
Также устанавливается обработчик сигналов консоли для обработки Ctrl+C и закрытия консоли.
*/

// Обработчик сигналов консоли
BOOL WINAPI CtrlHandler(_In_ DWORD dwCtrlType) {
    if (dwCtrlType == CTRL_C_EVENT) {
        printf("Ctrl-C event\n");
        exit(1);  // Завершение программы при получении сигнала Ctrl+C
    }
    else if (dwCtrlType == CTRL_CLOSE_EVENT) {
        printf("CTRL-CLOSE event\n");
        exit(2);  // Завершение программы при получении сигнала закрытия консоли
    }
    else {
        return FALSE;
    }
}

// Функция для вывода случайного числа с интервалом
void printRandomNumber() {
    while (TRUE) {
        printf("%f\n", (double)rand() / RAND_MAX);
        Sleep(1500);  // Приостановка выполнения потока на 1500 миллисекунд
    }
}

// Функция для вывода перевернутой строки ввода пользователя
void reversString() {
    while (TRUE) {
        char str[250];
        scanf_s("%s", str, 250);  // Ввод строки от пользователя
        printf("%s\n", _strrev(str));  // Вывод перевернутой строки
    }
}

int main() {
    // Установка обработчика сигналов консоли
    SetConsoleCtrlHandler(CtrlHandler, TRUE);

    // Создание двух потоков для выполнения функций printRandomNumber и reversString
    CreateThread(NULL, 0, printRandomNumber, NULL, 0, NULL);
    CreateThread(NULL, 0, reversString, NULL, 0, NULL);

    // Бесконечный цикл для ожидания завершения программы по сигналу
    while (TRUE) {}

    return 0;
}
