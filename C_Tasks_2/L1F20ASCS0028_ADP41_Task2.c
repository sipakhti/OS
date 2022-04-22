/**
 * @file L1F20ASCS0028_ADP41_Task2.c
 * @author your name (you@domain.com)
 * @brief Write a C Program which will create a child process using fork (). 
 * Now create communication between parent and child through pipe,
 * such that parent writes some message on pipe and child reads data from pipe and display it on terminal.
 * 
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

int main(){
    int fd[2];

    // Create pipe, exit if error
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // demo data
    char name[] = "Umer Mehmood";
    // create child process
    pid_t pid = fork();

    if (pid == 0) {
        // child process
        close(fd[WRITE]); // close write end
        char buf[100]; // buffer
        read(fd[READ], buf, 100); // child reads data from pipe sent by parent
        printf("%s\n", buf); // print data
        return 0;
    } else {
        // parent process
        close(fd[READ]); // close read end
        write(fd[WRITE], name, 13); // parent writing data to the pipe for child
        close(fd[WRITE]); // close write end
        return 0;
    }

}