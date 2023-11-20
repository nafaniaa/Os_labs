#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

// Пустой обработчик сигналов
void signalHandler(int signal)
{
  // Можно добавить дополнительную логику обработки сигналов
}

int main(int argc, char** argv)
{
  pid_t pid;
  pid_t w;
  int status;

  // Создание нового процесса
  pid = fork();

  // Проверка, выполняется ли код в дочернем процессе
  if (pid == 0) {
    sleep(3);  // Дочерний процесс ждет 3 секунды
    return 1;  // Дочерний процесс завершается с кодом 1
  }
  // Проверка, успешно ли создан новый процесс
  else if (pid == -1) {
    printf("ERROR! fork\n");
    exit(EXIT_FAILURE);
  }
  // Код для родительского процесса
  else {
    // Ожидание завершения дочернего процесса и получение статуса
    w = wait(&status);

    // Проверка успешности ожидания
    if (w == -1) {
      printf("waiting pid\n");
      exit(EXIT_FAILURE);
    }

    // Установка обработчиков сигналов для SIGTERM и SIGINT
    signal(SIGTERM, signalHandler);
    signal(SIGINT, signalHandler);

    // Проверка статуса завершения дочернего процесса и вывод соответствующего сообщения
    if (WIFEXITED(status))
      printf("\nNormal exit\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
      printf("\nKilled\n", WTERMSIG(status));
    else if (WIFSTOPPED(status))
      printf("\nStopped\n", WSTOPSIG(status));
    else if (WIFCONTINUED(status))
      printf("\nContinue\n");
  }

  return 0;
}

/* Этот код создает дочерний процесс, ждет его завершения,
обрабатывает сигналы SIGTERM и SIGINT в родительском процессе, 
и выводит соответствующее сообщение в зависимости от статуса завершения дочернего процесса.*/
