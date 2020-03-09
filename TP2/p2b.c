//
// Created by davidrocha on 09/03/20.
//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    int file1, file2;
    int auxr, auxw;
    char buffer[11];

    if (argc != 3) {
        printf("insufficient arguments\n");
        return 1;
    }
    file1 = open(argv[1], O_RDONLY);
    if (file1 == -1){
        perror(argv[1]);
        return 1;
    }

    file2 = open(argv[2], O_CREAT | O_WRONLY, 100);
    if (file2 == -1){
        perror(argv[2]);
        return 1;
    }

    while((auxr = read(file1, buffer, 11)) > 0){
        auxw = write(file2, buffer, auxr);
    }

    close(file1);
    close(file2);
    return 0;

}