/**
 * @file L1F20ASCS0028_ADP41_Task7.c
 * @author Umer Mehmood Khan Rana
 * @brief Write a C program to implement the following command.
            ls / -r > input.txt
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright sipakhti (c) 2022
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1


int main(){
    int from_ls[2];
    
    // create pipe
    if (pipe(from_ls) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork(); // create child process

    if (pid == 0)
    {
        //child process
        close(from_ls[READ]); // close read end in the child
        dup2(from_ls[WRITE], STDOUT_FILENO); // redirect stdout to pipe write end
        close(from_ls[WRITE]); // close write end in the child
        execlp("ls","ls", "/", "-r", NULL); // execute ls
        perror("execlp"); // error handling
        exit(EXIT_FAILURE); // exit child process
    }
    else {
        // parent process
        close(from_ls[WRITE]); // close write end in the parent
        char buffer[sizeof(char) * 512 * 1024]; // create buffer of 512KB
        read(from_ls[READ], buffer, 512 * 1024); // read from pipe
        FILE *fp = fopen("input.txt", "w"); // open file
        fprintf(fp, "%s", buffer); // write to file
        fclose(fp); // close file
        
    }
    return 0;
}