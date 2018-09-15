#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define    BUFFSIZE    1//4096

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    int n;
    char buf[BUFFSIZE];

    int input = open(argv[1], O_RDONLY);
    int output = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC);

    while ((n = read(input, buf, BUFFSIZE)) > 0) {
        if (write(output, buf, n) != n) {
            printf("write error");
        }
    }

    if (n < 0) {
        printf("read error");
    }

    return 0;
}
