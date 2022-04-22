/**
 * @file L1F20ASCS0028_ADP41_Task1.c
 * @author Umer Mehmood Khan Rana
 * @brief Write a C Program which will create a pipe. 
 *          Write your name on the pipe from write end.
 *          Then read data from pipe from the read end. 
 *          Then display data on terminal.
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright sipakhti (c) 2022
 * 
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


#define READ 0
#define WRITE 1

int main() {
    int fd[2];

    // if pipe is not created, then it will return -1
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // write your name on the pipe
    write(fd[WRITE], "Umer Mehmood", 13);
    // close write end
    close(fd[WRITE]);

    char buf[100];
    // read data from pipe
    read(fd[READ], buf, 100);
    close(fd[READ]);
    printf("%s\n", buf);
    return 0;

}