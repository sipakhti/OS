/**
 * @file L1F20ASCS0028_ADP41_Task5.c
 * @author Umer Mehmood Khan Rana
 * @brief Write a C program to implement the following command. 

            grep ‘Ali’ < input.txt | wc –c > output.txt

            Input.txt (student name and registration) 

            Ali 
            L1f18bscs0010

 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright sipakhti (c) 2022
 * 
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main(){
    int from_grep[2];
    int from_wc[2];

    if (pipe(from_grep) == -1) {
        perror("grep pipe");
        exit(EXIT_FAILURE);
    }
    if (pipe(from_wc) == -1) {
        perror("wc pipe");
        exit(EXIT_FAILURE);
    }

    // Create first child process
    pid_t pid_grep = fork();
    if (pid_grep == 0)
    {
        // child process GREP
        dup2(from_grep[WRITE], STDOUT_FILENO); // redirect stdout to pipe
        close(from_grep[WRITE]); // close write end
        close(from_grep[READ]); // close read end
        execlp("grep", "grep", "Ali", "input.txt", NULL); // execute grep
    }
    else
    {
        // parent process
        wait(NULL); // wait for child process to finish
        // Create second child process
        pid_t pid_wc = fork();
        if (pid_wc == 0)
        {
            // child process WC
            dup2(from_grep[READ], STDIN_FILENO); // hook stdin to pipe from grep
            close(from_grep[READ]); // close the read end of the pipe from grep
            close(from_grep[WRITE]); // close the write end of the pipe from grep
            dup2(from_wc[WRITE], STDOUT_FILENO); // redirect stdout to pipe of wc
            close(from_wc[WRITE]); // close write end
            close(from_wc[READ]); // close read end
            execlp("wc", "wc", "-c", NULL);
        }
        else
        {
            // parent process
            // close both ends of the pipe from grep because parent doesn't need them
            close(from_grep[READ]); 
            close(from_grep[WRITE]);
            // close write end of wc pipe because parent doesn't need it
            close(from_wc[WRITE]);
            wait(NULL); // wait for child process WC
            char buffer[100]; // buffer to store the output
            read(from_wc[READ], buffer, 100); // read the output from wc pipe
            FILE *fp = fopen("output.txt", "w"); // open output file
            fprintf(fp, "%s", buffer); // write to file the output from wc
            fclose(fp); // close file
            close(from_wc[READ]); // close read end of wc pipe
        }

    }
    return 0;

}