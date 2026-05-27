#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: forkloop <iterations>\n");
        exit(1);
    }
    int archparent = getppid();
    int iterations = strtol(argv[1], NULL, 10);
    int n = archparent;
    for (int i = 0; i < iterations; i++) {
        if (n==archparent) {
            n = fork();
        }
        if (n < 0) {
            perror("fork");
            exit(1);
        }

        printf("ppid = %d, pid = %d, i = %d\n", getppid(), getpid(), i);
    }
    while(wait(NULL) > 0);

    return 0;
}
