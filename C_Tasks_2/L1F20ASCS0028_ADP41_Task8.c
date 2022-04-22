/**
 * @file L1F20ASCS0028_ADP41_Task8.c
 * @author Umer Mehmood Khan Rana
 * @brief Write a C program to implement the following command.
            ls / -R 2 > input.txt | grep “m” < input.txt | sort > output.txt
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright sipakhti (c) 2022
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1


int main(){
    
    pid_t pid_ls = fork(); // create child process
    if (pid_ls == 0)
    {
        //child process

        FILE *fp = fopen("input.txt", "w"); // open input file to save the result of the cmd
        dup2(fileno(fp), STDOUT_FILENO); // redirect stdout to file
        fclose(fp);
        // fp = fopen("error log.txt","w"); // open error log file
        // dup2(fileno(fp),STDERR_FILENO); // hook stderr to error log
        // fclose(fp);
        execlp("ls", "ls","/", "-Imnt", "-R", NULL); // execute ls recursive except /mnt folder
    }
    else 
    {
        wait(NULL); // wait for ls to finish
        pid_t pid_grep = fork();
        if (pid_grep == 0)
        {
            // child process
            FILE *fp = fopen("input.txt", "r"); // open input file in which ls has stored the result
            dup2(fileno(fp), STDIN_FILENO); // hook stdin to input file from ls
            fclose(fp); // close file object
            fp = fopen("temp", "w"); // open temp file to store result of grep
            dup2(fileno(fp), STDOUT_FILENO); // hook stdout to temp file for grep
            fclose(fp); // close file object
            execlp("grep", "grep", "m", NULL); // execute grep
        }
        else 
        {
            wait(NULL); // wait for grep to finish
            pid_t pid_sort = fork();
            if (pid_sort == 0)
            {
                // Child process
                FILE *fp = fopen("temp", "r"); // open temp file in whicb grep data is stored
                dup2(fileno(fp), STDIN_FILENO); // hook stdin of sort to temp file
                fclose(fp); // close file object
                fp = fopen("output.txt", "w"); // open output file to store result of sort
                dup2(fileno(fp), STDOUT_FILENO); // hook stdout of sort to output file
                fclose(fp); // close file object
                execlp("sort", "sort", NULL); // execute sort
            }
            else 
            {
                // Parent process
                wait(NULL);
            }
        }

    }
    execlp("rm", "rm", "temp", NULL); // cleaup of temp files
    return 0;
}