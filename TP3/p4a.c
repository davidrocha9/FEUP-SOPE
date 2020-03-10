//
// Created by davidrocha on 09/03/20.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void){
    pid_t pid = fork();

    if (pid == -1){
        perror("fork error");
        return 1;
    }

    if (pid > 0)
        printf("Hello ");
    else
        printf("world!\n");
    return 0;
}