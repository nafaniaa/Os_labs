#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
/*
Этот код создает два потока с использованием библиотеки pthread, каждый из которых выполняет свою функцию:
вывод случайного числа с интервалом и вывод перевернутой строки ввода пользователя.
Также устанавливаются обработчики сигналов SIGINT и SIGTERM для обработки прерываний пользователем. 
*/

// Обработчик сигналов
void signalHandler(int signal) {
  if (signal == SIGINT) {
    printf("\nSIGINT %d", signal);
  }
  else if (signal == SIGTERM)
  {
    printf("\nSIGTERM %d", signal);
  }
  else {
    printf("\n%d", signal);
  }
  exit(0);
}

// Функция для вывода случайного числа с интервалом
void* printRandomNumber(void*) {
  while (TRUE) {
    printf("%f\n", (double)rand() / RAND_MAX);
    sleep(3);  // Приостановка выполнения потока на 3 секунды
  }
}

// Функция для вывода перевернутой строки ввода пользователя
void* reversString(void*) {
  while (TRUE) {
    char str[250];
    scanf("%s", str);  // Ввод строки от пользователя
    for (int i = strlen(str) - 1; i >= 0; --i) {
      printf("%c", str[i]);  // Вывод перевернутой строки
    }
    printf("\n");
  }
}

int main() {
  pthread_t thread1;
  pthread_t thread2;
  int first;
  int second;

  // Установка обработчиков сигналов SIGINT и SIGTERM
  signal(SIGINT, signalHandler);
  signal(SIGTERM, signalHandler);

  // Создание двух потоков для выполнения функций printRandomNumber и reversString
  first = pthread_create(&thread1, NULL, printRandomNumber, NULL);
  second = pthread_create(&thread2, NULL, reversString, NULL);

  while (TRUE) {}  // Бесконечный цикл для ожидания завершения программы

  return 0;
}
