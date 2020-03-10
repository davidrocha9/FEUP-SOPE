//
// Created by davidrocha on 09/03/20.
//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int global=1;

int main(void) {
    int local = 2;
    if(fork() > 0) { // Pai
        printf("PID = %d; PPID = %d\n", getpid(), getppid());
        global++;
        local--;
    } else { // Filho
        printf("PID = %d; PPID = %d\n", getpid(), getppid());
        global--;
        local++;
    }
    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
    return 0;
}