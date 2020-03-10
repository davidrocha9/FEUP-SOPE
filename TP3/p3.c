//
// Created by davidrocha on 09/03/20.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50

int main(void) {
    int i;
    pid_t pid;
    char str[10];
    switch (pid) {
        case -1:
            perror("fork");
            break;
        case 0:
            for (i=1; i <= MAX; i++){
                sprintf(str,"-%d",i);
                write(STDOUT_FILENO, str, strlen(str));
            }
            break;
        default:
            for (i=1; i<=MAX; i++){
                sprintf(str,"+%d",i);
                write(STDOUT_FILENO,str,strlen(str));
            }
    }
    return 0;
}