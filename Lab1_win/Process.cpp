#include<windows.h>
#include<stdio.h>

// Обработчик сигналов от консоли
BOOL WINAPI CtrlHandler(_In_ DWORD dwCtrlType) {
    // Обработка сигнала Ctrl+C
    if (dwCtrlType == CTRL_C_EVENT) {
        printf("Ctrl-C event\n");
        exit(1);
    }
    // Обработка сигнала закрытия консоли
    else if (dwCtrlType == CTRL_CLOSE_EVENT) {
        printf("CTRL-CLOSE event\n");
        exit(2);
    }
    // Если сигнал не распознан, возвращается FALSE
    else {
        return FALSE;
    }
}

int main(void) {
    // Установка обработчика сигналов
    if (SetConsoleCtrlHandler(CtrlHandler, TRUE)) {
        // Вывод сообщения ожидания сигнала
        printf("Waiting for signal\n");

        // Бесконечный цикл ожидания
        while (TRUE) {}

        // Достигнется только в случае ошибки
        return 0;
    }
    else {
        // Вывод сообщения об ошибке при установке обработчика сигналов
        printf("ERROR with setting control handler");
        return 1;
    }
}

//Этот код устанавливает обработчик событий консоли, который реагирует на Ctrl+C и закрытие консоли,
// выводит соответствующее сообщение и завершает программу.
