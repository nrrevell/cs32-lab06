#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: forkloop <iterations>\n");
        exit(1);
    }

    int iterations = strtol(argv[1], NULL, 10);
    int n = 10;
    for (int i = 1; i < iterations; i++) {
        if (n > 0) {
            n = fork();
            //printf("oh i'm forking it because i'm a parent, n is %d\n", n);
        }
        if (n == 0) {
            //printf("i'm not forking it because i'm a child, n is %d\n", n);
        }
        if (n < 0) {
            perror("fork");
            exit(1);
        }
        printf("ppid = %d, pid = %d, i = %d\n", getppid(), getpid(), i);
    }

    return 0;
}
