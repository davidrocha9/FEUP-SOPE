//
// Created by davidrocha on 15/03/20.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void){
    pid_t pid = fork();
    for (int x = 0; x < 3; x++) {
        switch (x) {
            case 0:
                switch(pid) {
                    case 0:
                        write(STDOUT_FILENO, "Hello ", 6);
                        break;
                    default:
                        break;
                }
                break;
            case 1:
                switch(pid) {
                    case 0:
                        write(STDOUT_FILENO, "my ", 3);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                switch(pid) {
                    case 0:
                        write(STDOUT_FILENO, "friends!\n", 10);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}