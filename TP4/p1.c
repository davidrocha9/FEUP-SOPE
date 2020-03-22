// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
    printf("In SIGINT handler ...\n");
}

int main(void) {
    struct sigaction action;

    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT,&action,NULL);

    if (signal(SIGINT, sigint_handler) < 0){
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(2);
    }


    printf("Sleeping for 30 seconds ...\n");
    int sleep_time = sleep(30);
    while (sleep_time != 0)
        sleep_time = sleep(sleep_time);
    printf("Waking up ...\n");
    exit(0);
}