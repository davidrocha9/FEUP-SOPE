//
// Created by davidrocha on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LEN 20

int main(int argc, char *argv[])
{
    struct termios term, oldterm;
    int i, file;
    char ch;

    if (argc != 2){
        printf("Wrong usage\n");
        return 1;
    }

    file = open(argv[1], O_WRONLY | O_CREAT, 512);
    if (file == -1){
        perror(argv[1]);
        return 1;
    }

    write(STDOUT_FILENO, "Nome/Classificacao?\n", 21);
    tcgetattr(STDIN_FILENO, &oldterm);
    term = oldterm;
    term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

    i=0;
    int students;
    while (students < 5) {
        while (i < MAX_LEN && read(STDIN_FILENO, &ch, 1) && ch != '\n') {
            write(STDOUT_FILENO, &ch, 1);
            write(file, &ch, 1);
        }
        write(file, "\n", 1);
        write(STDOUT_FILENO, "\n", 2);
        students++;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);

    return 0;
}