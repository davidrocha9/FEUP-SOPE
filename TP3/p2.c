#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void) {
    write(STDOUT_FILENO,"1",1);
    if(fork() > 0) {
        //write(STDOUT_FILENO,"2",1);
        //write(STDOUT_FILENO,"3",1);
        printf("2\n");
        printf("3\n");
    } else {
        //write(STDOUT_FILENO,"4",1);
        //write(STDOUT_FILENO,"5",1);
        printf("4\n");
        printf("5\n");
    }  write(STDOUT_FILENO,"\n",1);
    return 0;
}