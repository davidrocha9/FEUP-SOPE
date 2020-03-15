#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    pid_t pid;
    int status;

    if (argc != 2) {
        printf("usage: %s dirname\n",argv[0]);
        exit(1);
    }
    pid=fork();
    if (pid > 0) {
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
        wait(&status);

        if (WIFEXITED(status))      //9b)
            printf("Child terminated normally with code %d\n", WEXITSTATUS(status));

        else if (WIFSIGNALED(status))
            printf("Child terminated abnormally with code %d\n",WTERMSIG(status));
    }
    else if (pid == 0){
        execlp("ls","ls", "-laR", argv[1], NULL);
        exit(1);
    }
    exit(0);
}
