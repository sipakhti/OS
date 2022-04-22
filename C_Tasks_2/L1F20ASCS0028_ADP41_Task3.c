/**
 * @file L1F20ASCS0028_ADP41_Task3.c
 * @author Umer Mehmood Khan Rana
 * @brief Write a C Program which will create a child process using fork ().
 *  Now create communication bidirectional between parent and child through pipes, such that parent sends an integer to child, child receives this integer and displays.
 *  Now child doubles this integer value and sends again to parent, and parent receives this double value and displays on terminal.
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


#define READ 0
#define WRITE 1

int main(){
    int toParent[2], toChild[2];

    // Create the pipes, and check for errors
    if (pipe(toParent) == -1 || pipe(toChild) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create the child process
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        // Close unused ends of the pipes
        close(toParent[READ]); 
        close(toChild[WRITE]);

        int num;
        read(toChild[READ], &num, sizeof(int)); // Read the number from the pipe from the parent
        close(toChild[READ]); // Close the read end of the pipe 
        printf("CHILD: %d\n", num); 
        num *= 2; // Double the number
        write(toParent[WRITE], &num, sizeof(int)); // Write the number to the pipe for the parent
        close(toParent[WRITE]); // Close the write end of the pipe
        return 0;
    } else {
        // parent process
        close(toChild[READ]);
        close(toParent[WRITE]);
        int num = 10;
        write(toChild[WRITE], &num, sizeof(int)); // Write the number to the pipe for the child
        close(toChild[WRITE]); // Close the write end of the pipe
        read(toParent[READ], &num, sizeof(int)); // Read the number from the pipe from the child
        close(toParent[READ]); // Close the read end of the pipe
        printf("PARENT: %d\n", num);
        return 0;
    }
}