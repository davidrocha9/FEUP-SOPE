
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    FILE *file1, *file2;
    char buffer[11];

    if (argc != 3) {
        printf("insufficient arguments\n");
        return 1;
    }
    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "w");

    fread(buffer, 1, 11, file1);
    fwrite(buffer, 1, 11, file2);

    fclose(file1);
    fclose(file2);
    return 0;

}