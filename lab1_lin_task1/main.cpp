#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Обработчик сигналов
void signalHandler(int signal)
{
  // Обработка сигнала SIGINT (Ctrl+C)
  if (signal == SIGINT) {
    printf("\nSIGINT %d\n", signal);
    exit(0); // Завершение программы
	  // или break?
  }
  // Обработка сигнала SIGTERM
  else if (signal == SIGTERM) {
    printf("\nSIGTERM %d\n", signal);
    exit(0);  // Завершение программы
  }
  // Если получен другой сигнал, выводится общее сообщение
  else {
    printf("\nSignal\n");
    exit(0);  // Завершение программы
  }
}

int main(int argc, char** argv)
{
  // Установка обработчика сигнала SIGINT
  signal(SIGINT, signalHandler);

  // Установка обработчика сигнала SIGTERM
  signal(SIGTERM, signalHandler);

  // Бесконечный цикл ожидания сигналов
  while (true);
  return 0;
}
